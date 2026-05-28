#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

pair<int, int> dfs(int idx, int parent)
{
    int currOn = 1;
    int currOff = 0;
    for (const int next : graph[idx])
    {
        if (next == parent) { continue; }
        
        auto[on, off] = dfs(next, idx);
        currOn += min(on, off);
        currOff += on;
    }
    
    return {currOn, currOff};
}
    
int solution(int n, vector<vector<int>> lighthouse) 
{
    graph.resize(n);
    for (const auto& edge : lighthouse)
    {
        graph[edge[0] - 1].push_back(edge[1] - 1);
        graph[edge[1] - 1].push_back(edge[0] - 1);
    }
    
    auto[on, off] = dfs(0, -1);
    return min(on, off);
}