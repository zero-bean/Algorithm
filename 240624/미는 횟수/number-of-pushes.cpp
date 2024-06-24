#include <iostream>
#include <vector>
#include <string>

using namespace std;

void checkString(string(&str)[2]) {
    int count = 0;
    bool check = false;
    
    if (str[0] == str[1]) {
        cout << 0;
        return;
    }

    for (int i = 0; i < str[1].size(); i++) {
        char c = str[1].back();
        str[1].pop_back();
        str[1].insert(0, 1, c);

        count++;

        if (str[0] == str[1]) {
            check = true;
            break;
        }
    }

    !check ? cout << -1 : cout << count;
}

int main() {
    string str[2];

    for (string& s : str)
        cin >> s;

    checkString(str);

    return 0;
}