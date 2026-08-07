#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> InitializeGrid(const vector<vector<int>>& InRectangle)
{
    vector<vector<int>> grid(101, vector<int>(101, -1));
    
    // [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y]
    for (int idx=0; idx<InRectangle.size(); ++idx)
    {
        const int leftBottomX = InRectangle[idx][0] * 2;
        const int leftBottomY = InRectangle[idx][1] * 2;
        const int rightTopX = InRectangle[idx][2] * 2;
        const int rightTopY = InRectangle[idx][3] * 2;
        
        for (int i=leftBottomX; i<=rightTopX; ++i)
        {
            for (int j=leftBottomY; j<=rightTopY; ++j)
            {
                // 사각형의 테두리라면 이동 가능
                if (i==leftBottomX || j==leftBottomY || i==rightTopX || j==rightTopY)
                {
                    if (grid[j][i] == 0) { continue; }
                    
                    grid[j][i] = 1;
                    continue;
                }
                
                grid[j][i] = 0;
            }
        }
    }
    
    return grid;
}

bool CanGo(const int y, const int x) { return y >= 0 && x >= 0 && y <= 100 && x <= 100; }

int FindPathByUsingBFS(
    const vector<vector<int>>& Grid,
    const int characterX, 
    const int characterY, 
    const int itemX, 
    const int itemY)
{
    vector<vector<bool>> visited(101, vector<bool>(101, false));
    vector<vector<int>> result(101, vector<int>(101, 0));
    queue<pair<int, int>> q;
    const int dy[4] = {0, 0, 1, -1};
    const int dx[4] = {1, -1, 0, 0};
    
    q.push({characterY, characterX});
    
    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        
        visited[curr.first][curr.second] = true;
        
        for (int i=0; i<4; ++i)
        {
            const int ny = curr.first + dy[i];
            const int nx = curr.second + dx[i];
            
            if(!CanGo(ny, nx) || visited[ny][nx] || Grid[ny][nx] != 1) { continue; }
            
            q.push({ny, nx});
            result[ny][nx] = result[curr.first][curr.second] + 1;
            
            if (ny==itemY && nx==itemX) { return result[itemY][itemX] / 2; }
        }
    }
    
    return result[itemY][itemX] / 2;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // grid: -1 == 이동 불가능 / 0 == rectangle 내부 / 1 == 이동 가능 
    vector<vector<int>> grid = InitializeGrid(rectangle);
    
    return FindPathByUsingBFS(grid, characterX, characterY, itemX, itemY);
}