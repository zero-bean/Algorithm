#include <iostream>

#define MAX_N 1000
#define MOD 1000000007

using namespace std;

// 변수 선언
int n;

long long dp[MAX_N + 1];

int main() {
    // 입력:
    cin >> n;

    // 초기 조건 설정
    dp[0] = 1;
    dp[1] = 2;

    // 점화식에 따라 dp값 채우기
    // dp[i] = dp[i - 1] * 2 + dp[i - 2] * 3 +
    //         (dp[i - 3] + dp[i - 4] + dp[i - 5] + ... dp[0]) * 2
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3) % MOD;
        for(int j = i - 3; j >= 0; j--)
            dp[i] = (dp[i] + dp[j] * 2) % MOD;
    }
    
    cout << dp[n];
    return 0;
}