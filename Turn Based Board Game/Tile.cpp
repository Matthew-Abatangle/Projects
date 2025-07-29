#include "Tile.h"
#include <iostream>
#include <string>
using namespace std;
Tile::Tile(){
    _color = 'G';
    _type = "Regular";
    _effects = "None";
    _ppEffects = 0;
    _stamEffects = 0;
    _strenEffects = 0;
    _wEffects = 0;
}

Tile::Tile(char color, string type, string effects, int ppEffects, int stamEffects, int strenEffects, int wEffects){ // constructor
    _color = color;
    _type = type;
    _effects = effects;
    _ppEffects = ppEffects;
    _stamEffects = stamEffects;
    _strenEffects = strenEffects;
    _wEffects = wEffects;
}
// getters
char Tile::getColor(){
    return _color;
}
string Tile::getType(){
    return _type;
}
string Tile::getEffects(){
    return _effects;
}
int Tile::getPridePointEffects(){
    return _ppEffects;
}
int Tile::getStaminaEffects(){
    return _stamEffects;
}
int Tile::getStrengthEffects(){
    return _strenEffects;
}
int Tile::getWisdomEffects(){
    return _wEffects;
}
// setters 
void Tile::setColor(char color){
    _color = color;
}
void Tile::setType(string type){
    _type = type;
}
void Tile::setEffects(string effects){
    _effects = effects;
}
void Tile::setPridePointEffect(int ppEffects){
    _ppEffects = ppEffects;
}
void Tile::setStaminaEffect(int stamEffects){
    _stamEffects = stamEffects;
}
void Tile::setStrengthEffect(int strenEffects){
    _strenEffects = strenEffects;
}
void Tile::setWisdomEffect(int wEffects){
    _wEffects = wEffects;
}





