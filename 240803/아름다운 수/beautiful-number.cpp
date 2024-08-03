#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> dp(n);

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 6;

    for (int i = 3; i < n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout << dp[n-1];

    return 0;
}