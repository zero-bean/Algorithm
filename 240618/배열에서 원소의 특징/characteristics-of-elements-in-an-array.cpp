#include <iostream>

using namespace std;

int main() {
    int temp = 0;

    for (int i=0; i<10; i++) {
        int a;
        cin >> a;
        if (a%3==0) {
            cout << temp;
            break;
        } else {
            temp = a;
        }
    }

    return 0;
}