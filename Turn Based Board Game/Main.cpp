#include "GameManager.h"
#include <iostream>
using namespace std;

void displayMainMenu(GameManager gameManager) {
    cout << "======================" << endl;
    cout << "     MAIN MENU        " << endl;
    cout << "======================" << endl;

    for (int i = 0; i < 2; i++) {
        Player currentPlayer = gameManager.getPlayer(i);
        cout << "Player " << i + 1 << ": " << currentPlayer.getName() << endl;
        cout << "Position: " << gameManager.getPlayerPosition(i) << endl;
        currentPlayer.printStats();
        cout << "----------------------" << endl;
    }

    cout << "1. Roll Dice" << endl;
    cout << "2. Quit Game" << endl;
    cout << "Enter your choice: ";
}

int main() {
    GameManager gameManager;
    int choice;

    // Game Initialization
    gameManager.initializeGame();

    int currentPlayerIndex = 0;

    // Main Game Loop
    while (!gameManager.isGameOver()) {
        displayMainMenu(gameManager);
        cin >> choice;

        if (choice == 1) {
            // Play the current player's turn
            gameManager.playTurn(currentPlayerIndex);
            // Move to the next player
            currentPlayerIndex = (currentPlayerIndex + 1) % 2;
        } else if (choice == 2) {
            cout << "Thanks for playing! Goodbye!" << endl;
            return 0; // Exit the game
        } else {
            cout << "Invalid choice. Please select 1 or 2." << endl;
        }
    }

    // Announce the winner
    gameManager.announceWinner();
    return 0;
}
