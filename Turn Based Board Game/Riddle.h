#ifndef RIDDLE_H
#define RIDDLE_H
#include <string>
#include <iostream>
using namespace std;

class Riddle{
private:
    string _question;
    string _answer;

public:
    Riddle();
    Riddle(string question, string answer);

    string getQuestion();
    string getAnswer();

    void setQuestion(string question);
    void setAnswer(string answer);

    bool isCorrectAnswer(string playerAnswer);
};
#endif
