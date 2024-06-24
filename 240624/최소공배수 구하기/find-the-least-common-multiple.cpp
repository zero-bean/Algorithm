#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}

void lcm(int n, int m) {
    cout << n * m / gcd(n, m);
}

int main() {
    int n, m;

    cin >> n >> m;

    lcm(n, m);

    return 0;
}