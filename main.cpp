#include "Gronsfeld.h"

int main() {
    Gronsfeld gr;
    cout << "1 - Зашифрувати речення\n"
            "2 - Розшифрувати речення\n"
            "Введіть пункт меню : ";
    string user;
    getline(cin, user);

    cout << "Речення : ";
    string sentence;
    getline(cin, sentence);
    cout << "Ключ : ";
    string key;
    getline(cin, key);
    cout << "Результат : ";

    if(user == "1"){
        cout << gr.encrypt(sentence, key, true);
    }
    else if(user == "2"){
        cout << gr.encrypt(sentence, key, false);
    }
    else{
        return 0;
    }

    return 0;
}
