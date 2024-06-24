#include <iostream>
#include <vector>
#include <string>

using namespace std;

void moveLeftCharacter(string& str) {
    char startChar = str[0];
    str.erase(0, 1);
    str.push_back(startChar);
}

void moveRightCharacter(string& str) {
    char lastChar = str.back();
    str.pop_back();
    str.insert(str.begin(), lastChar);
}

void changeString(string(&str)[2]) {
    for (const char& c : str[1]) {
        if (c == 'L')
            moveLeftCharacter(str[0]);
        else if (c == 'R')
            moveRightCharacter(str[0]);
    }
}

int main() {
    string str[2];

    for (string& s : str)
        getline(cin, s);

    changeString(str);

    cout << str[0];

    return 0;
}