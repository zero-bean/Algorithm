#include <iostream>

using namespace std;

void drawStars(int size) {
    for (int i=1; i<=size; i++) {
        for (int j=0; j<i; j++) {
            cout << "*";
        }
        cout << endl;
        cout << endl;
    }

    for (int i=size-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            cout << "*";
        }
        cout << endl;
        cout << endl;
    }
}

int main() {
    int n;

    cin >> n;

    drawStars(n);

    return 0;
}