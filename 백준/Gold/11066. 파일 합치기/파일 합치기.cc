#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> dp;
vector<int> files;

int Solve(int start, int end) {
    if (dp[start][end] != numeric_limits<int>::max())
        return dp[start][end];

    if (start == end)
        return dp[start][end] = 0;

    if (end == start + 1)
        return dp[start][end] = files[start] + files[end];

    for (int mid = start; mid < end; mid++) {
        int left = Solve(start, mid);
        int right = Solve(mid + 1, end);
        dp[start][end] = min(dp[start][end], left + right);
    }

    return dp[start][end] += dp[0][end] - dp[0][start - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K;

        cin >> K;
            
        files = vector<int>(K + 1);
        dp = vector<vector<int>>(K + 1, vector<int>(K + 1, numeric_limits<int>::max()));
        dp[0][0] = 0;

        for (int i = 1; i <= K; i++) {
            cin >> files[i];
            dp[0][i] = dp[0][i - 1] + files[i];
        }

        cout << Solve(1, K) << endl;
    }

    return 0;
}