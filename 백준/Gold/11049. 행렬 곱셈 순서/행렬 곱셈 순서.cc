#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<pair<int, int>> matrix;
vector<vector<int>> dp;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    matrix.resize(N + 1);
    dp.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
        cin >> matrix[i].first >> matrix[i].second;

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i <= N - len + 1; i++) {
            int j = i + len - 1;

            dp[i][j] = numeric_limits<int>::max();

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][N] << endl;

    return 0;
}
