#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve(vector<vector<ll>>& dp, int n) {
    if (n == 0) {
        cout << "1 0" << endl;
        return;
    }
    else if (n == 1) {
        cout << "0 1" << endl;
        return;
    }
    else if (n == 2) {
        cout << "1 1" << endl;
        return;
    }

    dp[0][0] = dp[1][1] = dp[1][2] = dp[0][2] = 1;
    dp[0][1] = dp[1][0] = 0;

    for (int i = 3; i <= n; i++) {
        dp[1][i] = dp[1][i - 1] + dp[0][i - 1];
        dp[0][i] = dp[1][i - 1];
    }

    cout << dp[0][n] << " " << dp[1][n] << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        vector<vector<ll>> dp(2, vector<ll>(N + 1));

        solve(dp, N);
    }

    return 0;
}