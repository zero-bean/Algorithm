#include <iostream>
#include <vector>

using namespace std;

vector<int> coins;
int N, K;

void Solve() {
    vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= K; j++)
            dp[j] += dp[j - coins[i]];
    }

    cout << dp[K] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    coins.resize(N);
    for (int& coin : coins)
        cin >> coin;

    Solve();

    return 0;
}