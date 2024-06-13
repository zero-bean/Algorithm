#include <iostream>

using namespace std;

int main() {
    int count = 0, sum = 0;

    while (true) {
        int n;
        cin >> n;

        if (n < 20 || n > 29)
         break;

        count++;
        sum+=n;
    }

    cout << fixed;
    cout.precision(2);
    cout << (double)sum / count;

    return 0;
}