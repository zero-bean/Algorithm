#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> dp;
int n;

void find_Max() {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
    }
}

void initialize_DP() {
    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
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

    cout << dp[n - 1][n - 1];

    return 0;
}