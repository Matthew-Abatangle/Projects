#include "RandomEvent.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
RandomEvent::RandomEvent(){ // constructor
    _description = "";
    _pathType = 2; // path 0 and 1 are choices
    _advisorEffects = 0;
    _ppEffects = 0;
    _stamEffects = 0;
    _strenEffects = 0;
    _wEffects = 0;
}
RandomEvent::RandomEvent(string description, int pathType, int advisorEffects, int ppEffects, int stamEffects, int strenEffects, int wEffects){
    _description = description;
    _pathType = pathType;
    _advisorEffects = advisorEffects;
    _ppEffects = ppEffects;
    _stamEffects = stamEffects;
    _strenEffects = strenEffects;
    _wEffects = wEffects;
}
// getters
string RandomEvent::getDescription(){
    return _description;
}
int RandomEvent::getPathType(){
    return _pathType;
}
int RandomEvent::getAdvisorEffects(){
    return _advisorEffects;
}
int RandomEvent::getPridePointEffects(){
    return _ppEffects;
}
int RandomEvent::getStaminaEffects(){
    return _stamEffects;
}
int RandomEvent::getStrengthEffects(){
    return _strenEffects;
}
int RandomEvent::getWisdomEffects(){
    return _wEffects;
}
// setters
void RandomEvent::setDescription(string description){
    _description = description;
}
void RandomEvent::setPathType(int pathType){
    _pathType = pathType;
}
void RandomEvent::setAdvisorEffect(int advisorEffects){
    _advisorEffects = advisorEffects;
}
void RandomEvent::setPridePointEffect(int ppEffects){
    _ppEffects = ppEffects;
}
void RandomEvent::setStaminaEffect(int stamEffects){
    _stamEffects = stamEffects;
}
void RandomEvent::setStrengthEffect(int strenEffects){
    _strenEffects = strenEffects;
}
void RandomEvent::setWisdomEffect(int wEffects){
    _wEffects = wEffects;
}
// applies event for player
Player RandomEvent::applyEvent(Player player, Advisor advisor){
    cout << "Debug: Advisor assigned to player: " << advisor.getName() << endl;
    if (advisor.protectsAgainst(_advisorEffects)){
        cout << player.getName() << " is protected by " << advisor.getName() << "!" << endl;
        return player;
    }
    player.addPridePoints(_ppEffects);
    player.addStamina(_stamEffects);
    player.addStrength(_strenEffects);
    player.addWisdom(_wEffects);

    cout << "Event: " << _description << endl;
    cout << "Effects applied to " << player.getName() << ":" << endl;
    player.printStats();
    return player;
}

