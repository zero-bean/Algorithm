#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    // 0은 깔끔, 1은 뾰족
    vector<vector<int>>dp(2, vector<int>((2 * n + 1) + 1, 0));
    int answer = 0;
    
    dp[0][1] = 1;
    dp[1][1] = 1;
    
    for (int i = 2; i <= 2 * n + 1; ++i)
    {
        if (i % 2 == 0 && tops[i / 2 - 1] == 1) // top이 존재한다면
        {
            dp[0][i] = (2 * dp[0][i-1] + dp[1][i-1]) % 10007;
            dp[1][i] = dp[0][i-1] % 10007;
        }
        else // top이 없다면
        {
            dp[0][i] = (dp[0][i-1] + dp[1][i-1]) % 10007;
            dp[1][i] = dp[0][i-1] % 10007;
        }
    }
    
    answer = dp[0][2*n+1] % 10007;
    
    return answer;
}