#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str[2];

    for (string& s : str)
        getline(cin, s);

    for (string s : str) {
        for (char c : s) {
            if (c != ' ')
                cout << c;
        }
    }

    return 0;
}