#ifndef GRONSFELD_H
#define GRONSFELD_H

#include <string>
#include <iostream>
using namespace std;

class Gronsfeld {
    bool keyCheck(const string &key);
    void changeKeyLength(string &key, int sentenceSize);
    bool sentenceCheckAndIncrementRegister(string &sentence);
    int charToInt(char ch);
    bool examination(string &sentence, string &key);
public:
    Gronsfeld() = default;
    string encrypt(string sentence, string key, bool e);
};


#endif
