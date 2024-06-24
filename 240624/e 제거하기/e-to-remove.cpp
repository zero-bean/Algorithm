#include <iostream>
#include <string>

using namespace std;

void removeCharacter(string& str) {

    for (int i = 0; i<str.size(); i++) {
        if (str[i] == 'e') {
            str.erase(i, 1);
            break;
        }
    }
}

int main() {
    string str;

    getline(cin, str);

    removeCharacter(str);

    cout << str;

    return 0;
}