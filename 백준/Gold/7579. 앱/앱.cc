#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> dp = {};
    vector<int> value = {};
    vector<int> cost = {};
    int N = 0, M = 0, size = 0;

    cin >> N >> M;

    value = vector<int>(N + 1, 0);
    cost = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> value[i];

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        size += cost[i];
    }

    dp = vector<vector<int>>(N + 1, vector<int>(size + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= size; j++) {
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i - 1][j - cost[i]] + value[i]);
                continue;
            }

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= size; i++) {
        if (dp[N][i] >= M) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}