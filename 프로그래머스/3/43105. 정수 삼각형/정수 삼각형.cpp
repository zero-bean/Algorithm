#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    const int size = triangle.size();
    vector<vector<int>> dp(size);
    dp[0].push_back(triangle[0][0]);
    
    for (int i=1; i<size; ++i)
    {
        dp[i].resize(i+1, 0);
    
        for (int j=0; j<i+1; ++j)
        {
            const int left = j-1;
            const int right = j;
            
            if (left >= 0)
            {
                dp[i][j] = triangle[i][j] + dp[i-1][left];
            }
            
            if (right < dp[i-1].size())
            {
                dp[i][j] = max(dp[i][j], triangle[i][j] + dp[i-1][right]);
            }
        }
    }
    
    int max = 0;
    for (int i=0; i<size; ++i)
    {
        if (dp[size-1][i] > max) { max = dp[size-1][i]; }
    }

    return max;
}