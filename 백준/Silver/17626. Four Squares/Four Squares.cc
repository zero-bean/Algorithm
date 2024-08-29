#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int main() {
    cin >> n;

    if (n <= 1) {
        cout << n << endl;
        return 0;
    }

    dp.resize(n + 1, 5);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int j = 1;

        while (j * j <= i) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
            j++;
        }
    }

    cout << dp[n] << endl;

    return 0;
}