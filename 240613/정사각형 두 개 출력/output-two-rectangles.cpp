#include <iostream>

using namespace std;

void drawSquare(int size) {
    for (int i=0; i < size; i++) {
        for (int j=0; j < size; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    drawSquare(n);
    drawSquare(n);

    return 0;
}