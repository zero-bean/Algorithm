#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;


void Solve() {
    if (N % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= N; i += 2) {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = i - 4; j >= 0; j -= 2)
            dp[i] += (dp[j] * 2);
    }

    cout << dp[N] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    Solve();

    return 0;
}