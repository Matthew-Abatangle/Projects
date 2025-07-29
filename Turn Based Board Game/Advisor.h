#ifndef ADVISOR_H
#define ADVISOR_H

#include <string>
using namespace std;

class Advisor{
private:
    string _name;
    string _ability;
    string _description;
    int _protectionType;
public:
    Advisor();
    Advisor(string name, string ability, string description, int protectionType);

    string getName();
    string getDescription();
    int getProtectionType();
    string getAbility();

    void setName(string name);
    void setAbility(string ability);
    void setDescription(string desc);
    void setProtectionType(int type);

    bool protectsAgainst(int eventType);
};
#endif

