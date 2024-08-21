#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> dp;
    int n;
    
    cin >> n;
    
    dp.resize(n+1);
    dp[0] = dp[1] = 1;
    dp[2] = 3;
    
    for (int i=3; i<=n; i++)
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    
    cout << dp[n] << endl;
    
    return 0;
}