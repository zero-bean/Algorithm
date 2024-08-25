#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

void solve(int n, const vector<vector<int>>& g) {
    vector<vector<int>> dp(2, vector<int>(n, 0));
    int ans;

    if (n == 1) {
        ans = max(g[0][0], g[1][0]);
        cout << ans << endl;
        return;
    }

    dp[0][0] = g[0][0];
    dp[1][0] = g[1][0];
    dp[0][1] = dp[1][0] + g[0][1];
    dp[1][1] = dp[0][0] + g[1][1];

    for (int i = 2; i < n; i++) {
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + g[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + g[1][i];
    }

    ans = max(dp[0][n - 1], dp[1][n - 1]);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>>grid(2, vector<int>(n, 0));
        for (vector<int>& g : grid) {
            for (int& i : g)
                cin >> i;
        }

        solve(n, grid);
    }

    return 0;
}