#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<int> answer;
    
    vector<vector<int>> graph(n+1);
    for (const auto& road : roads)
    {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    const int sourceSize = sources.size();
    for (int i=0; i<sourceSize; ++i)
    {
        vector<bool> visited(n+1, false);
        queue<pair<int, int>> q;
        int totalCost = -1;
        
        visited[sources[i]] = true;
        q.push({sources[i], 0});
        
        while(!q.empty())
        {
            const auto[node, cost] = q.front();
            q.pop();
            
            if (node == destination)
            {
                totalCost = cost;
                break;
            }
            
            visited[node] = true;
            
            for (const auto& neighbor : graph[node])
            {
                if (visited[neighbor]) { continue; }
                
                q.push({neighbor, cost + 1});
            }
        }
        
        answer.push_back(totalCost);    
    }
    
    return answer; 
}