#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    n /= 2;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            dp[i] += dp[i - 1 - j] * dp[j] % 987654321;
        dp[i] %= 987654321;
    }

    cout << dp[n] << endl;

    return 0;
}