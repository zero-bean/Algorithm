#include <string>
#include <vector>

using namespace std;

void solve(vector<int>& dp, int curr, const int dest, const int n)
{
    if (curr > dest) { return; }

    if (curr+n <= dest)
    {
        if (dp[curr] + 1 < dp[curr+n])
        {
            dp[curr+n] = dp[curr] + 1;
            solve(dp, curr+n, dest, n);
        }
    }
    
    if (curr*2 <= dest)
    {
        if (dp[curr] + 1 < dp[curr*2])
        {
            dp[curr*2] = dp[curr] + 1;
            solve(dp, curr*2, dest, n);
        }
    }
    
    if (curr*3 <= dest)
    {
        if (dp[curr] + 1 < dp[curr*3])
        {
            dp[curr*3] = dp[curr] + 1;
            solve(dp, curr*3, dest, n);
        }
    }
}

int solution(int x, int y, int n) 
{
    vector<int> dp(y+1, 1'000'001);
    dp[x] = 0;
    solve(dp, x, y, n);
    
    return (dp[y] == 1'000'001 ? -1 : dp[y]);
}