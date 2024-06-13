#include <iostream>

using namespace std;

void drawRightTriangle(int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j < 2*i + 1; j++) {
            cout << "*";
        }
        cout << endl;    
    }
}

int main() {
    int n;

    cin >> n;
    
    drawRightTriangle(n);
    
    return 0;
}