#include <iostream>

using namespace std;

void drawTwoTriangles(int size) {
    for (int i=0; i < size; i++) {
        for (int j=0; j < size * 2; j++) {
            if (j < size - i || j >= size + i) {
                cout <<"*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    
    cin >> n;

    drawTwoTriangles(n);

    return 0;
}