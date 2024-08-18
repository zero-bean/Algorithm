#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int main() {
    cin >> n;

    dp.resize(n+1);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;

    for (int i=4; i<=n; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) %  1000000007;

    cout << dp[n];

    return 0;
}