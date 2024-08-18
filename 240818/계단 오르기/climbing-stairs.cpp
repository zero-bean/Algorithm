#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int up_Stairs(int n) {
    for (int i=4; i<=n; i++)
        dp[i] = (dp[i-2] + dp[i-3]) % 10007;

    return dp[n];
}

int main() {
    cin >> n;

    dp.resize(n + 1, 0);
    dp[2] = 1;
    dp[3] = 1;

    cout << up_Stairs(n);

    return 0;
}