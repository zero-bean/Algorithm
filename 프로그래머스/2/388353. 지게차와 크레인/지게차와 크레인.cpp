#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isConnectedFromOutside(const int maxY, const int maxX, const int y, const int x)
{
    return y<0 || y>=maxY || x<0 || x>=maxX;
}

void PickUpContainers(vector<string>& inStorage, const char target)
{
    const int height = inStorage.size();
    const int width = inStorage[0].size();
    vector<pair<int, int>> result{};
    
    for (int i=0; i<height; ++i)
    {
        for (int j=0; j<width; ++j)
        {
            if (inStorage[i][j] != target) { continue; }
            
            queue<pair<int, int>> q{};
            vector<vector<bool>> visited(height, vector<bool>(width, false));
            const int dy[4] = {0,0,1,-1};
            const int dx[4] = {1,-1,0,0};
            
            q.push({i, j});
            visited[i][j] = true;
            bool isDone = false;
            
            while(!q.empty())
            {
                const auto[cy, cx] = q.front();
                q.pop();
                
                for (int k=0; k<4; ++k)
                {
                    const int ny = cy + dy[k];
                    const int nx = cx + dx[k];
                    
                    if (isConnectedFromOutside(height, width, ny, nx))
                    {
                        result.push_back({i,j});
                        isDone = true;
                        break;
                    }
                    
                    if (visited[ny][nx]) { continue; }
                    
                    visited[ny][nx] = true;
                    if(inStorage[ny][nx] == '0')
                    {
                        q.push({ny, nx});
                    }
                }
                
                if (isDone) { break; }
            }
        }
    }
    
    for (const auto[y, x] : result)
    {
      inStorage[y][x] = '0';   
    }
}

// 크레인을 이용하여 해당 유형의 모든 컨테이너를 삭제
void PickUpAllContainers(vector<string>& inStorage, const char target)
{
    const int height = inStorage.size();
    const int width = inStorage[0].size();
    for (int i=0; i<height; ++i)
    {
        for (int j=0; j<width; ++j)
        {
            if (inStorage[i][j] == target)
            {
                inStorage[i][j] = '0';
            }
        }
    }
}

int calculateLeftContainers(const vector<string>& inStorage)
{
    int result = 0;
    const int height = inStorage.size();
    const int width = inStorage[0].size();
    for (int i=0; i<height; ++i)
    {
        for (int j=0; j<width; ++j)
        {
            if (inStorage[i][j] != '0')
            {
                result++;
            }
        }
    }
    
    return result;
}

int solution(vector<string> storage, vector<string> requests) 
{
    for (const string& request : requests)
    {
        if (request.size() == 2)
        {
            PickUpAllContainers(storage, request[0]);
        }
        else if (request.size() == 1)
        {
            PickUpContainers(storage, request[0]);
        }
    }
    
    return calculateLeftContainers(storage);
}