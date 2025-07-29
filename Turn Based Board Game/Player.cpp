#include "Player.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Player::Player(){
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pride_points = 20000;
}

Player::Player(string name, int strength, int stamina, int wisdom){
    _name = name;
    _pride_points = 20000;
    _age = 1;
    if(_stamina>1000 || _stamina<100){
        _stamina = 100;
    }
    _stamina = stamina;
    if(_strength>1000 || _stamina<100){
        _strength = 100;
    }
    _strength = strength;
    if(_wisdom>1000 || _wisdom<100){
        _wisdom = 100;
    }
    _wisdom = wisdom;
}

string Player::getName(){
    return _name;
}
int Player::getStrength(){
    return _strength;
}
int Player::getStamina(){
    return _stamina;
}
int Player::getWisdom(){
    return _wisdom;
}
int Player::getPridePoints(){
    return _pride_points;
}
int Player::getAge(){
    return _age;
}
Advisor Player::getAdvisor(){
    return _advisor;
}
void Player::setName(string name){
    _name = name;
}
void Player::setStrength(int strength) {
    if(strength >= 100 && strength <= 1000){
        _strength = strength;
    } else {
        _strength = 100;
    }
}
void Player::setStamina(int stamina) {
    if(stamina >= 100 && stamina <= 1000){
        _stamina = stamina;
    } else {
        _stamina = 100;
    }
}
void Player::setWisdom(int wisdom) {
    if (wisdom < 100) {
        _wisdom = 100; 
    } else if (wisdom > 1000) {
        _wisdom = 1000; 
    } else {
        _wisdom = wisdom; 
    }
}
void Player::setPridePoints(int pridePoints) { 
    if(pridePoints >= 0){
        _pride_points = pridePoints;
    } else {
        _pride_points = 0;
    }
}
void Player::setAge(int age) {
    if(age >= 1 && age <= 20){
        _age = age;
    } else {
        _age = 1;
    }
}
void Player::setAdvisor(Advisor advisor){
    _advisor = advisor;
}

void Player::addStrength(int value) { 
    if(_strength + value <= 1000){
        _strength += value;
    } else {
        _strength = 1000;
    }
}

void Player::addStamina(int value) { 
    if(_stamina + value <= 1000){
        _stamina += value;
    } else {
        _stamina = 1000; 
    }
}

void Player::addWisdom(int amount) {
    _wisdom += amount;
    // if (_wisdom > 1000) {
    //     _wisdom = 1000;
    // }
    // if (_wisdom < 0) {
    //     _wisdom = 0; 
    // }
}

void Player::addPridePoints(int value) { 
    if(_pride_points + value >= 0){ 
        _pride_points += value;
    } else {
        _pride_points = 0; 
    }
}

void Player::addAge(int value) { 
    if(_age + value <= 20){
        _age += value;
    } else {
        _age = 20; 
    }
}

void Player::trainCub(int strength, int stamina, int wisdom){
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
    if(_pride_points - 5000 >= 0){
        _pride_points -= 5000;
    } 
    else{
        _pride_points = 0;
    }
    if(_strength < 100) _strength = 100;
    if(_stamina < 100) _stamina = 100;
    if(_wisdom < 100) _wisdom = 100;
}
void Player::toPrideLands() {
    _pride_points += 5000;
    _stamina += 200;
    _strength += 200;
    _wisdom += 200;
}
void Player::printStats(){
    cout<<_name<<", age "<<_age<<endl;
    cout<<"Strength: "<<_strength<<endl;
    cout<<"Stamina: "<<_stamina<<endl;
    cout<<"Wisdom: "<<_wisdom<<endl;
    cout<<"Pride Points: "<<_pride_points<<endl;
    if (!_advisor.getName().empty()){
        cout << "Advisor: " << _advisor.getName() << " (" << _advisor.getAbility() << ")" << endl;
        cout<< "Description: "<<_advisor.getDescription()<<endl;
    } else {
        cout << "Advisor: None" << endl;
    }
    cout<<endl;
}
