#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
int n;

int Solve() {
    int ans = 1'000 * 1'000 + 1;

    for (int first_color = 0; first_color < 3; first_color++) {
        vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));

        dp[1][first_color] = grid[1][first_color];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + grid[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + grid[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + grid[i][2];
        }

        for (int last_color = 0; last_color < 3; last_color++) {
            if (last_color != first_color) {
                ans = min(ans, dp[n][last_color]);
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    grid.assign(n + 1, vector<int>(3, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    cout << Solve() << endl;

    return 0;
}