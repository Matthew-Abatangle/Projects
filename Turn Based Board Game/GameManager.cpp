#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;
GameManager::GameManager(){
    currentPlayerIndex = 0;
    srand(time(0));
} // loads character into game
vector<Player> GameManager::loadCharacters(string filename){
    vector<Player> characters;
    ifstream file(filename);
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string name;
        int age, strength, stamina, wisdom, pridePoints;

        getline(ss, name, '|');
        ss >> age; ss.ignore();
        ss >> strength; ss.ignore();
        ss >> stamina; ss.ignore();
        ss >> wisdom; ss.ignore();
        ss >> pridePoints;

        Player character(name, strength, stamina, wisdom);
        character.setAge(age);
        character.setPridePoints(pridePoints);

        characters.push_back(character);
    }

    file.close();
    return characters;
} // loads player into the game
void GameManager::loadPlayers(){
    vector<Player> characters = loadCharacters("characters.txt");
    for (int i = 0; i < 2; i++){
        cout << "Available characters:" << endl;
        for (int j = 0; j < characters.size(); j++){
            cout << j + 1 << ". " << characters[j].getName() << " (Age: " << characters[j].getAge()
                 << ", Strength: " << characters[j].getStrength()
                 << ", Stamina: " << characters[j].getStamina()
                 << ", Wisdom: " << characters[j].getWisdom()
                 << ", Pride Points: " << characters[j].getPridePoints() << ")" << endl;
        }
        int choice;
        cout << "Player " << i + 1 << ", select your character (1-" << characters.size() << "): ";
        cin >> choice;

        while(choice < 1 || choice > characters.size()){
            cout << "Invalid choice. Please select a valid character: ";
            cin >> choice;
        }
        players[i] = characters[choice - 1];
        characters.erase(characters.begin() + (choice - 1));
        players[i].printStats();
    }
}
Player GameManager::getPlayer(int index){
    if (index >= 0 && index < 2) {
        return players[index];
    }
    cerr << "Invalid player index!" << endl;
    return Player();
} // player chooses path and advisor
Player GameManager::choosePath(int playerIndex) {
    Player player = getPlayer(playerIndex);
    cout << "Choose a path for " << player.getName() << ":" << endl;
    cout << "1. Cub Training (+500 Stamina, +500 Strength, +1000 Wisdom, -5000 Pride Points, You Recieve an Advisor Now)" << endl;
    cout << "2. Straight to the Pride Lands (+200 Stamina, +200 Strength, +200 Wisdom, +5000 Pride Points, You Do Not Recieve an Advisor Now)" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) { // looks at cub training
        player.trainCub(500, 500, 1000);
        cout << player.getName() << " has chosen Cub Training!" << endl;
        cout << "Choose an advisor for " << player.getName() << ":" << endl;
        for (int i = 0; i < advisors.size(); i++) {
            cout << i + 1 << ". " << advisors[i].getName() << " (" << advisors[i].getAbility() << ")" << endl;
    }

        int advisorChoice;
        cin >> advisorChoice;
        while (advisorChoice < 1 || advisorChoice > advisors.size()) {
            cout << "Invalid choice. Please select a valid advisor: ";
            cin >> advisorChoice;
        }

        player.setAdvisor(advisors[advisorChoice - 1]);
        advisors.erase(advisors.begin() + (advisorChoice - 1));
        cout << player.getName() << " has chosen " << player.getAdvisor().getName() << " as their advisor!" << endl;

    } else if (choice == 2) { // looks at pride lands 
        player.toPrideLands();
        cout << player.getName() << " has chosen Straight to the Pride Lands!" << endl;
    } else {
        cout << "Invalid choice. Defaulting to Straight to the Pride Lands." << endl;
        player.toPrideLands();
    }

    return player;
}
// loads game
void GameManager::initializeGame() {
    string begin;
    cout<<"Welcome to The Game of Life!"<<endl;
    cout<<"Press Enter to Begin..."<<endl;
    cin.get();
    loadAdvisors();
    loadPlayers(); // Load players from characters.txt
    for (int i = 0; i < 2; i++) {
        players[i] = choosePath(i); // Assign updated player
    }

    loadRandomEvents("random_events.txt");
    loadRiddles("riddles.txt");
    board = Board(2); // Initialize board for two players
    }

// loads in random events
void GameManager::loadRandomEvents(string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '/' || line.find("Description") != string::npos) {
            continue;
        }
        stringstream ss(line);
        string description, pathTypeStr, advisorEffectStr, prideEffStr;

        // Parse the fields
        getline(ss, description, '|');
        getline(ss, pathTypeStr, '|');
        getline(ss, advisorEffectStr, '|');
        getline(ss, prideEffStr, '|');

        // Validate parsed fields
        if (description.empty() || pathTypeStr.empty() || advisorEffectStr.empty() || prideEffStr.empty()) {
            cerr << "Error: Missing field in line: " << line << endl;
        }

        try {
            // Convert strings to integers and create a RandomEvent
            RandomEvent event(
                description,
                stoi(pathTypeStr),
                stoi(advisorEffectStr),
                stoi(prideEffStr),
                0, // Assuming other effects are not yet implemented
                0,
                0
            );

            randomEvents.push_back(event);
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid field in line: " << line << endl;
        }
    }

    file.close();

} // loads in riddles
void GameManager::loadRiddles(string filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error: Could not open " << filename << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(file, line)) {
        if (line.empty() || line[0] == '/' || line.find("Question") != string::npos) {
            continue; // Skip empty lines, comments, or headers
        }

        stringstream ss(line);
        string question, answer;

        getline(ss, question, '|');
        getline(ss, answer, '|');

        if (question.empty() || answer.empty()) {
            cerr << "Error: Missing question or answer in line: " << line << endl;
            continue;
        }

        riddles.push_back(Riddle(question, answer));
    }

    file.close();

    // Debug: Print loaded riddles
    cout << "Loaded " << riddles.size() << " riddles from " << filename << "." << endl;
    for (size_t i = 0; i < riddles.size(); ++i) {
        cout << "Riddle " << (i + 1) << ": " << riddles[i].getQuestion() << ", Answer: " << riddles[i].getAnswer() << endl;
    }
}

void GameManager::loadAdvisors(){
    advisors = {
        Advisor("Rafiki", "Invisibility", "Avoids negative Pride Point events.", 1),
        Advisor("Nala", "Night Vision", "Avoids stamina loss during night events.", 2),
        Advisor("Sarabi", "Energy Manipulation", "Avoids wisdom loss events.", 3),
        Advisor("Zazu", "Weather Control", "Avoids weather-related events.", 4),
        Advisor("Sarafina", "Super Speed", "Avoids movement penalties.", 5)
    };
}
void GameManager::playGame() {
    bool gameOver;
    if(!isGameOver()){

    } else {
        announceWinner();
    }
    // set bool for gameover
    // keep game running while game over is false      
    // check if any player has reached the final tile
    // check win condition
}
void GameManager::playTurn(int playerIndex) {
    Player player = players[playerIndex]; // Make a copy of the player
    cout << "Player " << player.getName() << "'s turn!" << endl;

    // Roll the dice and move the player
    int steps = board.rollDice();
    cout << "Rolled a " << steps << "!" << endl;

    if (board.movePlayer(playerIndex, steps)) {
        cout << "Player " << player.getName() << " reached Pride Rock!" << endl;
        return; // Exit if the player has reached the final tile
    }

    // Get the tile the player landed on
    int currentPosition = board.getPlayerPosition(playerIndex);
    cout << "Player landed at position: " << currentPosition << endl;

    // Retrieve the tile and apply its effects
    Tile currentTile = board.getTileAt(playerIndex, currentPosition);
    player = applyTileEffect(player, currentTile); // Update the player's stats

    // Save the updated player back to the players array
    players[playerIndex] = player;

    // Print updated stats for the player
    player.printStats();

    // Display the board after the turn
    board.displayBoard(); // Pass the players and count (assuming 2 players)
}

Player GameManager::applyTileEffect(Player player, Tile tile) {
    cout << "Applying effect for tile type: " << tile._type << endl;
 // handling regular tiles
    if (tile._type == "Regular") {
        cout << "Landing on a Regular Tile!" << endl;
        if (randomEvents.empty()) {
            cerr << "Error: randomEvents is empty!" << endl;
            return player;
        }
        RandomEvent event = randomEvents[rand() % randomEvents.size()];
        Advisor advisor = player.getAdvisor();
        
        cout << "Before applying event:" << endl;
        player.printStats(); // Debug before
        player = event.applyEvent(player, player.getAdvisor());
        cout << "After applying event:" << endl;
        player.printStats();
    } 
    else if (tile._type == "Oasis") { // handles oasis tiles
        cout << "You feel refreshed! Gained 200 Stamina, Strength, and Wisdom." << endl;
        player.addStamina(200);
        player.addStrength(200);
        player.addWisdom(200);
    } 
    else if (tile._type == "Counseling") { // handles counseling tiles
        cout << "Counseling Tile! Choose or switch your advisor." << endl;

        // Display available advisors
        for (size_t i = 0; i < advisors.size(); ++i) {
            cout << i + 1 << ". " << advisors[i].getName() 
                 << " (" << advisors[i].getDescription() << ")" << endl;
        }

        // Prompt the player to select an advisor
        int choice;
        cout << "Choose an advisor for " << player.getName() << ": ";
        cin >> choice;

        // Validate input
        while (choice < 1 || choice > advisors.size()) {
            cout << "Invalid choice. Please select a valid advisor: ";
            cin >> choice;
        }

        // Assign the chosen advisor to the player
        player.setAdvisor(advisors[choice - 1]);
        cout << player.getName() << " has chosen " << advisors[choice - 1].getName() 
             << " as their advisor!" << endl;
    } 
    else if (tile._type == "Graveyard") { // handles graveyards 
        cout << "Uh-oh! Graveyard tile. Lost 100 Stamina, Strength, and Wisdom." << endl;
        player.addStamina(-100);
        player.addStrength(-100);
        player.addWisdom(-100);
    } 
    else if (tile._type == "Hyenas") { // handles hyenas 
        cout << "Hyenas! Moved back and lost stamina." << endl;
        player.addStamina(-300);
    } 
    else if (tile._type == "Challenge") { // handles challenges 
        cout << "Challenge Tile! Solve a riddle to gain wisdom." << endl;

        // Select a random riddle
        Riddle riddle = riddles[rand() % riddles.size()];
        cout << "Riddle: " << riddle.getQuestion() << endl;
        cout << "Your answer: ";
        
        string answer;
        cin >> answer;

        if (riddle.isCorrectAnswer(answer)) {
            cout << "Correct! Gained 100 Wisdom." << endl;
            player.addWisdom(100);
        } else {
            cout << "Incorrect. Lost 50 Wisdom." << endl;
            // player.addWisdom(-50);
            player.setWisdom(player.getWisdom() - 50);
            int currentWisdom = player.getWisdom();
            cout << "Current Wisdom: " << currentWisdom << endl;

        }
    }
    // Existing logic for other tiles
    return player;
}


bool GameManager::isGameOver(){ // checks if game is over
    for (int i = 0; i < 2; i++) { 
        if (board.getPlayerPosition(i) != board.getBoardSize() - 1) {
            return false;
        }
    }
    return true; 
}
void GameManager::announceWinner(){ // announces winner by checking highest pride points 
    int winnerIndex = 0;
    int highestPridePoints = players[0].getPridePoints();

    for (int i = 1; i < 2; i++) {
        if (players[i].getPridePoints() > highestPridePoints) {
            winnerIndex = i;
            highestPridePoints = players[i].getPridePoints();
        }
    }
    cout << "The winner is " << players[winnerIndex].getName() << " with "
         << highestPridePoints << " Pride Points!" << endl;
}
vector<RandomEvent> GameManager::getRandomEvents(){
    return randomEvents;
}
int GameManager::getPlayerPosition(int playerIndex){
    return board.getPlayerPosition(playerIndex);
}

