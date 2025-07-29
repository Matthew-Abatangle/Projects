#include "Advisor.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Advisor::Advisor(){ // constructor
    _name = "";
    _ability = "";
    _description = "";
    _protectionType = 0;
}
Advisor::Advisor(string name, string ability, string description, int protectionType){
    _name = name;
    _ability = ability;
    _description = description;
    _protectionType = protectionType;
}

string Advisor::getName(){
    return _name;
}
string Advisor::getDescription(){
    return _description;
}
int Advisor::getProtectionType(){
    return _protectionType;
}
string Advisor::getAbility(){
    return _ability;
}

void Advisor::setName(string name){
    _name = name;
}
void Advisor::setAbility(string ability){
    _ability = ability;
}
void Advisor::setDescription(string description){
    _description = description;
}
void Advisor::setProtectionType(int protectionType){
    _protectionType = protectionType;
}
// when calling i will use the setters to make each advisor

bool Advisor::protectsAgainst(int eventType){
    return _protectionType == eventType;
}
// since these are both ints, if the number is the same then the advisor can protect
// but if they arent then they cannot protect