#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Advisor.h"
using namespace std;
class Player{
    private:
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age;
        Advisor _advisor;
    public:
        Player();
        Player(string name, int strength, int stamina, int wisdom);

        string getName();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        int getAge();
        Advisor getAdvisor();

        void setName(string name);
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom);
        void setPridePoints(int pride_points);
        void setAge(int age);
        void setAdvisor(Advisor advisor);

        void addStrength(int value);
        void addStamina(int value);
        void addWisdom(int value);
        void addPridePoints(int value);
        void addAge(int value);
        
        void trainCub(int strength, int stamina, int wisdom);
        void toPrideLands();
        void printStats();
};

#endif