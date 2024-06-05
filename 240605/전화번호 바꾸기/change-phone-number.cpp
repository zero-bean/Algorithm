#include <iostream>
#include <string>

using namespace std;

int main() {
    string number;
    cin >> number;

    for (int i=0; i< number.size(); i++) {
        if (i >= 4 && i <= 7) {
            cout << number[i + 5];
        } else if (i >= 9 && i <= 12) {
            cout << number[i - 5];
        } else {
            cout << number[i];
        }
    }

    return 0;
}