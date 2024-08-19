#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> dp;
int n;

void find_Max() {
    for (int i = 1; i < n; i++) {
        for (int j = n-2; j >= 0; j--)
            dp[i][j] = min(dp[i][j + 1], dp[i - 1][j]) + grid[i][j];
    }
}

void initialize_DP() {
    dp[0][n-1] = grid[0][n-1];

    for (int i = n-2; i >= 0; i--) {
        dp[0][i] = dp[0][i + 1] + grid[0][i];
    }

    for (int i = 1; i<n; i++)
        dp[i][n-1] = dp[i - 1][n-1] + grid[i][n-1];
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, 0));

    for (vector<int>& g : grid) {
        for (int& i : g)
            cin >> i;
    }

    initialize_DP();

    find_Max();

    cout << dp[n - 1][0];

    return 0;
}