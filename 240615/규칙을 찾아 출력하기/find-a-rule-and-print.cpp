#include <iostream>

using namespace std;

void drawStars(int size) {
    for (int i=1; i<=size; i++) {
        cout << "* ";
    }
    cout << endl;
    for (int j=1; j<size; j++) {
        for (int k=1; k<size; k++) {
            if (k <= j) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "*" << endl;
    }
}

int main() {
    int n;

    cin >> n;

    drawStars(n);

    return 0;
}