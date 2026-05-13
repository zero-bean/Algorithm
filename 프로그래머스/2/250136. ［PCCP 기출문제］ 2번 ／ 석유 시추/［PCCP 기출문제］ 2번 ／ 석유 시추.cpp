#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;

bool inline isInRange(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < M; }

void BFS(const vector<vector<int>>& land, vector<vector<int>>& landMap, 
         vector<int>& landMapResult, const int idx, const pair<int, int> pos)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    
    q.push(pos);
    landMap[pos.first][pos.second] = idx;
    cnt++;
    
    const int dy[4] = {0, 0, 1, -1};
    const int dx[4] = {1, -1, 0, 0};
    
    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
                
        for (int i = 0; i < 4; ++i)
        {
            const int ny = dy[i] + curr.first;
            const int nx = dx[i] + curr.second;
            
            if (isInRange(ny, nx) && land[ny][nx] == 1 && landMap[ny][nx] == 0)
            {
                landMap[ny][nx] = idx;
                q.push({ny, nx});
                cnt++;
            }
        }
    }
    landMapResult.push_back(cnt);
}

int solution(vector<vector<int>> land) 
{
    N = land.size();
    M = land[0].size();
    
    int idx = 1;
    vector<vector<int>> landMap(N, vector<int>(M, 0));
    vector<int> landMapResult(1);
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (land[i][j] == 1 && landMap[i][j] == 0)
            {
                BFS(land, landMap, landMapResult, idx, {i, j});
                idx++;
            }
        }
    }
    
    int answer = 0;
    
    for (int j = 0; j < M; ++j) 
    {
        int tmp = 0;
        set<int> usedIdx; 
        
        for (int i = 0; i < N; ++i) 
        {
            int currentId = landMap[i][j];
            if (currentId > 0 && usedIdx.find(currentId) == usedIdx.end())
            {
                tmp += landMapResult[currentId];
                usedIdx.insert(currentId);
            }
        }
        answer = max(answer, tmp);
    }
    
    return answer;
}