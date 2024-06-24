#include <iostream>
#include <string>

using namespace std;

void changeString(string& str) {
    for (const char& c : str) {
        if (c >= 65 && c <= 90)
            cout << (char)(c + 32);
        else
            cout << (char)(c - 32);
    }
}

int main() {
    string str;

    getline(cin, str);

    changeString(str);

    return 0;
}