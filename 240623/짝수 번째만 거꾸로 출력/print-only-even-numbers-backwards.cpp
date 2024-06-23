#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    int i;

    getline(cin, s);

    i = s.length() % 2 == 0 ? (s.length() - 1) : (s.length() - 2);

    for (; i >= 0; i -= 2)
        cout << s[i];

    return 0;
}