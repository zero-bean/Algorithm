#include <iostream>

using namespace std;

int main() {
    char c;

    cin.get(c);

    c != 'a' ? c -= 1 : c = 'z';

    cout << c;

    return 0;
}