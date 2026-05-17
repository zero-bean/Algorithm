#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;

bool inline isInRange(const int y, const int x) { return y>=0 && y<N && x>=0 && x<M; }

vector<int> solution(vector<string> maps) 
{
    N = maps.size();
    M = maps[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<int> answer;
    queue<pair<int, int>> q{};

    const int dy[4] = {0,0,1,-1};
    const int dx[4] = {1,-1,0,0};
    
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            if (visited[i][j])
            {
                continue;
            }

            int days = 0;
            visited[i][j] = true;
            
            if (maps[i][j] != 'X')
            {
                q.push({i,j});
                days += (maps[i][j] - '0');
            }
            
            while(!q.empty())
            {
                const pair<int, int> curr = q.front();
                q.pop();
                
                for (int k=0; k<4; ++k)
                {
                    const int ny = dy[k] + curr.first;
                    const int nx = dx[k] + curr.second;
                    
                    if (isInRange(ny, nx) == false || 
                        visited[ny][nx] ||
                        maps[ny][nx] == 'X')
                    {
                        continue;
                    }
                    
                    visited[ny][nx] = true;
                    days += (maps[ny][nx] - '0');
                    q.push({ny, nx});
                }
            }
            
            if (days != 0)
            {
                answer.push_back(days);
            }
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    sort(answer.begin(), answer.end(), less<int>());
    
    return answer;
}