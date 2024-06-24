#include <iostream>
#include <string>

using namespace std;

void removeCharacters(string& str) {
    for (int i = 0; i < str.size();) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str.erase(i, 1);
        else
            i++;
    }
}

int main() {
    string str[2];

    for (string& s : str) {
        getline(cin, s);
        removeCharacters(s);
    }

    cout << stoi(str[0]) + stoi(str[1]);

    return 0;
}