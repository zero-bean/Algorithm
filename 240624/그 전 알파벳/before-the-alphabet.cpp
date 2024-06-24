#include <iostream>

using namespace std;

int main() {
    char c;

    cin.get(c);

    c != 'z' ? c -= 1 : c = 'a';

    cout << c;

    return 0;
}