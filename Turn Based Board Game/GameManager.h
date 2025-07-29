#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Board.h"
#include "RandomEvent.h"
#include "Riddle.h"
#include "Advisor.h"
#include <iostream>
#include <vector>
using namespace std;

class GameManager{
private:
    Board board;
    Player players[2];
    vector<RandomEvent> randomEvents;
    vector<Riddle> riddles;
    vector<Advisor> advisors;
    int currentPlayerIndex;

public:
    GameManager();

    void initializeGame();
    vector<Player> loadCharacters(string filename);
    void loadPlayers();
    void loadRandomEvents(string filename);
    void loadRiddles(string filename);
    void loadAdvisors();
    void playGame();
    void playTurn(int playerIndex);
    Player applyTileEffect(Player player, Tile tile);
    bool isGameOver();
    void announceWinner();
    vector<RandomEvent> getRandomEvents();
    Player getPlayer(int index);
    Player choosePath(int playerIndex);
    void chooseAdvisor(Player player);
    void checkWinCondition();
    int getPlayerPosition(int playerIndex);
};
#endif
