#include "Gronsfeld.h"

bool Gronsfeld::keyCheck(const string &key) {
    int i = 0;
    while(i != key.size()){
        if(key[i] >= 48 && key[i] <= 57){
            ++i;
        }
        else{
            cerr << "Ключ містить нецифрові значення !\n";
            return false;
        }
    }
    return true;
}

void Gronsfeld::changeKeyLength(string &key, int sentenceSize) {
    if(key.size() < sentenceSize){
        int keyIndex = 0;
        while(key.size() != sentenceSize){
            key.insert(key.end(), key[keyIndex]);
            ++keyIndex;
        }
    }
}

bool Gronsfeld::sentenceCheckAndIncrementRegister(string &sentence) {
    int i = 0;
    while(i != sentence.size()){
        if((sentence[i] >= 97 && sentence[i] <= 122)){
            sentence[i] = char(sentence[i] - 32);
        }
        else if(!(sentence[i] >= 65 && sentence[i] <= 90) &&
                sentence[i] != ' '){
            cerr << "Рядок містить неприпустимий символ '" << sentence[i] << "' !\n";
            return false;
        }
        ++i;
    }
    return true;
}

int Gronsfeld::charToInt(char ch) {
    return ch - 48;
}

bool Gronsfeld::examination(string &sentence, string &key) {
    if(sentenceCheckAndIncrementRegister(sentence) && keyCheck(key)){
        changeKeyLength(key, sentence.size());
        return true;
    }
    else{
        return false;
    }
}

string Gronsfeld::encrypt(string sentence, string key, bool e) {
    if(!examination(sentence, key)){
        return "";
    }
    int j;
    for(int i = 0; i < sentence.size(); ++i){
        if(sentence[i] == ' '){
            continue;
        }
        if(e){
            j = sentence[i] + charToInt(key[i]);
            if(j >= 91){
                j -= 26;
            }
        }
        else{
            j = sentence[i] - charToInt(key[i]);
            if(j <= 64){
                j += 26;
            }
        }
        sentence[i] = char(j);
    }
    return sentence;
}
































