#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        for (int k=0; k<=i-1; k++)
            dp[i] += dp[k] * dp[i-1-k];
    }

    cout << dp[n];

    return 0;
}