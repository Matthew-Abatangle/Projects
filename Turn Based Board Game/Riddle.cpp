#include "Riddle.h"
#include <iostream>
#include <string>
#include <iomanip>

#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;

Riddle::Riddle(){
    _question = "";
    _answer = "";    
}
Riddle::Riddle(string question, string answer){
    _question = question;
    _answer = answer;
}

string Riddle::getQuestion(){
    return _question;
}
string Riddle::getAnswer(){
    return _answer;
}

void Riddle::setQuestion(string question){
    _question = question;
}
void Riddle::setAnswer(string answer){
    _answer = answer;
}

// gets rid of white space due to issue 
string removeWhitespace(string input) {
    string output;
    for (char c : input) {
        if (!std::isspace(c)) {
            output += c;
        }
    }
    return output;
}
// checks if answer is correct
bool Riddle::isCorrectAnswer(string answer){
    string trimmedPlayerAnswer = removeWhitespace(answer);
    string trimmedCorrectAnswer = removeWhitespace(_answer);

    // Debugging statements
    cout << "Correct answer: " << trimmedCorrectAnswer <<endl;

    return trimmedPlayerAnswer == trimmedCorrectAnswer;
}
