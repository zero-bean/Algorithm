#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int main() {
    cin >> n;

    dp.resize(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n];

    return 0;
}