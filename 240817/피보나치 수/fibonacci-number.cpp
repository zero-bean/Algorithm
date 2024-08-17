#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int Fibonacci(int n) {
    for (int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n]; 
}

int main() {
    cin >> n;

    dp.resize(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;

    cout << Fibonacci(n);

    return 0;
}