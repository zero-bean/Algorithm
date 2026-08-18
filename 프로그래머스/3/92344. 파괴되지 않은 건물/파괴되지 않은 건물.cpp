#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    int R = board.size();
    int C = board[0].size();
    
    vector<vector<int>> prefix(R + 1, vector<int>(C + 1, 0));
    
    for (int i = 0; i < skill.size(); ++i)
    {
        const vector<int>& curr = skill[i];
        const int value = (curr[0] == 1) ? -curr[5] : curr[5];
        
        prefix[curr[1]][curr[2]] += value;
        prefix[curr[1]][curr[4] + 1] += -value;
        prefix[curr[3] + 1][curr[2]] += -value;
        prefix[curr[3] + 1][curr[4] + 1] += value; 
    }
    
    for (int i = 0; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            prefix[i][j] += prefix[i][j - 1];
        }
    }
    
    for (int j = 0; j <= C; ++j)
    {
        for (int i = 1; i <= R; ++i)
        {
            prefix[i][j] += prefix[i - 1][j];
        }
    }
    
    int answer = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] + prefix[i][j] > 0)
            {
                answer++;
            }
        }
    }
    
    return answer;
}