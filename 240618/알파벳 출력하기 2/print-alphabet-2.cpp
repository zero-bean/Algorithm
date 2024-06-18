#include <iostream>

using namespace std;

int main() {
    int n, value = 65;

    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=n-i; j<n; j++) {
            cout << "  ";
        }

        for (int j=0; j<n-i; j++, value++) {
            if (value == 91)
                value = 65;
            cout << char(value) << " ";
        }
        cout << endl;
    }

    return 0;
}