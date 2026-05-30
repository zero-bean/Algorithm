#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> Graph;

// 1. S->B 최단 비용
// 2. S->A 최단 비용
// 3. A->B 최단 비용
// 4. B->A 최단 비용

// Case 1. S->A->B 비용
// Case 2. S->B->A 비용
// Case 3. S->A 비용 + S->B 비용

struct PqCmp
{
  bool operator()(const pair<int, int>& a, const pair<int, int>& b)
  {
      return a.second > b.second;
  }
};

vector<int> calculateTotalCost(const int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, PqCmp> pq;
    vector<int> result(Graph.size(), 2'000'001);
    vector<bool> visited(Graph.size(), false);
    
    pq.push({start, 0});
    result[start] = 0;
    
    while(pq.empty() == false)
    {
        auto[idx, cost] = pq.top();
        pq.pop();
        
        if (visited[idx]) { continue; }
        
        result[idx] = cost;
        visited[idx] = true;

        for (const auto& node : Graph[idx])
        {
            auto[nextIdx, nextCost] = node;
            
            if (visited[nextIdx]) { continue; }
            
            pq.push({nextIdx, cost + nextCost});
        }
    }
    
    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    Graph.resize(n+1);
    for (const vector<int>& fare : fares)
    {
        Graph[fare[0]].push_back({fare[1], fare[2]});
        Graph[fare[1]].push_back({fare[0], fare[2]});
    }
    
    const vector<int> fromStart = calculateTotalCost(s);
    const vector<int> fromA = calculateTotalCost(a);
    const vector<int> fromB = calculateTotalCost(b);
    int minCost = fromStart[a] + fromStart[b];
    for (int i=1; i<=n; ++i)
    {
        minCost = min(minCost, fromStart[i] + fromA[i] + fromB[i]);
    }
    
    return minCost;
}