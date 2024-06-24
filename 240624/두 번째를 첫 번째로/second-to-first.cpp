#include <iostream>
#include <string>

using namespace std;

void replaceString(string& str) {
    char c = str[1];

    for (char& target : str) {
        if (target == c)
            target = str[0];
    }
}

int main() {
    string str;

    getline(cin, str);

    replaceString(str);

    cout << str;

    return 0;
}