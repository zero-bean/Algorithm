#include <iostream>

using namespace std;

int main() {
    int n, count = 0;

    cin >> n;

    for (int i=1; n>=1; i++, count++) {
        n /= i;
    }

    cout << count;

    return 0;
}