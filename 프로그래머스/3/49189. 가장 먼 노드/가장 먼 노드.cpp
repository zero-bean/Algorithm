#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solve(const vector<vector<int>>& graph, const int n)
{
    vector<int> history(n+1, 0);
    vector<bool> visited(n+1, false);
    history[0] = history[1] = -1;
    visited[0] = visited[1] = true;
    
    queue<pair<int, int>> originQ;
    for (int i=0; i<graph[1].size(); ++i)
    {
        originQ.push({graph[1][i], 1});
    }
    
    while (!originQ.empty())
    {
        // first == 노드 / second == 거리
        pair<int, int> curr = originQ.front();
        originQ.pop();
        
        if (visited[curr.first]) { continue; }
        
        visited[curr.first] = true;
        history[curr.first] = curr.second; 

        for (int i=0; i<graph[curr.first].size(); ++i)
        {
            if (visited[graph[curr.first][i]]) { continue; }
            
            originQ.push({graph[curr.first][i], curr.second + 1});
        }

    }
    
    return history;
}

int solution(int n, vector<vector<int>> edge) 
{
    // 초기화
    vector<vector<int>> graph(n+1);
    for (const vector<int>& e : edge)
    {
        int sp = e[0];
        int lp = e[1];
        graph[sp].push_back(lp);
        graph[lp].push_back(sp);
    }
    
    vector<int> result = solve(graph, n);
    
    // 큰 순으로 정렬하고, 가장 앞 value랑 일치한 개수 반환
    sort(result.begin(), result.end(), greater<int>());
    
    const int maxValue = result[0];
    int answer = 0;
    for (int i=0; i<=n; ++i)
    {
        if (result[i] != maxValue) { break; }
        
        answer++;
    }
    
    return answer;
}