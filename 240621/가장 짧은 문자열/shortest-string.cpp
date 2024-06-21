#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int min = 20, max = 0;
    string str[3];

    for (string& s : str)
        cin >> s;

    for (string s : str) {
        if (min > s.length())
            min = s.length();

        if (max < s.length())
            max = s.length();
    }

    cout << max - min;

    return 0;
}