#include <iostream>

using namespace std;

int main() {
    int n, count = 0;

    cin >> n;

    for (int i=0; i<n; i++) {
        int value;
        cin >> value;

        if (value == 2)
            count++;

        if (count == 3) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}