#include <iostream>

using namespace std;

int main() {
    int a, b;
    bool result = false;

    cin >> a >> b;

    for (int i=a; i <= b; i++) {
        if (1920 % i == 0 && 2880 % i == 0) {
            result = true;
            break;
        }
    }

    result ? cout << "1" : cout << "0";

    return 0;
}