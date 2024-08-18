#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int up_Stairs(int n) {
    if (n <= 3)
        return dp[n];

    return dp[n] = (up_Stairs(n - 2) + up_Stairs(n - 3)) % 10007;
}

int main() {
    cin >> n;

    dp.resize(n + 1, 0);
    dp[2] = 1;
    dp[3] = 1;

    cout << up_Stairs(n);

    return 0;
}