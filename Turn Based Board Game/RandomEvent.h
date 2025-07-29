#ifndef RANDOM_EVENT_H
#define RANDOM_EVENT_H
#include <string>
#include "Player.h"
#include "Advisor.h"
using namespace std;

class RandomEvent{
private:
    string _description;
    int _pathType;
    int _advisorEffects;
    int _ppEffects;
    int _stamEffects;
    int _strenEffects;
    int _wEffects;

public:
    RandomEvent();
    RandomEvent(string description, int pathType, int advisorEffects, int ppEffects, int stamEffects, int strenEffects, int wEffects);

    string getDescription();
    int getPathType();
    int getAdvisorEffects();
    int getPridePointEffects();
    int getStaminaEffects();
    int getStrengthEffects();
    int getWisdomEffects();

    void setDescription(string description);
    void setPathType(int pathType);
    void setAdvisorEffect(int advisorEffects);
    void setPridePointEffect(int ppEffects);
    void setStaminaEffect(int stamEffects);
    void setStrengthEffect(int strenEffects);
    void setWisdomEffect(int wEffects);

    Player applyEvent(Player player, Advisor advisor);
};
#endif
