#include <iostream>

using namespace std;

void drawStars(int size) {
    for (int i=1; i<=size; i++) {
        if (i % 2 != 0)
            cout << "*" << endl;
        else {
            for (int j=0; j<i; j++)
                cout << "* ";
            cout << endl;
        }
    }
}

int main() {
    int n;

    cin >> n;

    drawStars(n);

    return 0;
}