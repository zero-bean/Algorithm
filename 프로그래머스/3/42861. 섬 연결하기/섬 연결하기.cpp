#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int unionFind(vector<int>& graphParent, const int node)
{
    if (graphParent[node] == node)
    {
        return node;
    }
    
    return graphParent[node] = unionFind(graphParent, graphParent[node]);
}

int solution(int n, vector<vector<int>> costs) 
{
    vector<int> graphParent(n, 0);
    for (int i=0; i<n; ++i) { graphParent[i] = i; }
    
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){ return a[2] < b[2]; });
    
    int answer = 0;
    int cnt = 0;
    for (int i=0; i<costs.size(); ++i)
    {        
        const int a = costs[i][0];
        const int b = costs[i][1];
        const int cost = costs[i][2];
        
        const int ParentA = unionFind(graphParent, a);
        const int ParentB = unionFind(graphParent, b);
        if (ParentA != ParentB)
        {
            graphParent[ParentB] = ParentA;
            answer+=cost;
            cnt++;
        }
   
        if (cnt == n-1) { return answer; }
    }
    
    return -1;
}