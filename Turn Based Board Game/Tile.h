#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <string>
using namespace std;
class Tile{
    public:
        char _color;
        string _type;
        string _effects;
        int _ppEffects, _stamEffects, _strenEffects, _wEffects; 
        
        Tile();
        Tile(char color, string type, string effects, int ppEffects, int stamEffects, int strenEffects, int wEffects);

        char getColor();
        string getType();
        string getEffects();
        int getPridePointEffects();
        int getStaminaEffects();
        int getStrengthEffects();
        int getWisdomEffects();

        void setColor(char color);
        void setType(string type);
        void setEffects(string effects);
        void setPridePointEffect(int ppEffects);
        void setStaminaEffect(int stamEffects);
        void setStrengthEffect(int strenEffects);
        void setWisdomEffect(int wEffects);
        
};
#endif  
