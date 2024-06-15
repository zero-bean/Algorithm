#include <iostream>

using namespace std;

void printRightSquare(int size) {
    int count = 9;

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++, count--) {
            if (count == 0)
                count = 9;
            cout << count;
        }
        cout << endl;
    }
}

int main() {
    int n;

    cin >> n;

    printRightSquare(n);

    return 0;
}