#include <iostream>

using namespace std;

void drawStars(int size) {
    for (int i=1; i<=size; i++) {
        for (int j=i; j<=size; j++) {
            cout << "* ";
        }
        cout << endl;
        for (int k=0; k<i; k++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cin >> n;

    drawStars(n);

    return 0;
}