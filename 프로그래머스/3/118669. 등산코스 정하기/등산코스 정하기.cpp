#include <string>
#include <vector>
#include <queue>
#include <algorithm> // sort 사용을 위해 추가

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    auto[minIdx, minIntensity] = pair<int, int>(-1, 10'000'001);
    const int pathSize = paths.size();
    
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i=0; i<pathSize; ++i)
    {
        const vector<int> path = paths[i];
        graph[path[0]].push_back({path[1], path[2]});
        graph[path[1]].push_back({path[0], path[2]});
    }
    
    vector<bool> isSummit(n + 1, false);
    for (int j=0; j<summits.size(); ++j)
    {
        isSummit[summits[j]] = true;
    }
    
    struct PqCmp
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
        {
            return a.second > b.second; 
        }
    };
    priority_queue<pair<int,int>, vector<pair<int, int>>, PqCmp> pq{};
    
    // 무한 루프를 막고 최소 비용을 기록할 배열 (필수 추가)
    vector<int> visitedIntensity(n + 1, 10'000'001);
    
    // 모든 gate를 큐에 삽입
    for (int i=0; i<gates.size(); ++i)
    {
        pq.push({gates[i], 0});
        visitedIntensity[gates[i]] = 0;
    }

    // 탐색 시작
    while(!pq.empty())
    {
        auto[curr, cost] = pq.top(); 
        pq.pop();
        
        if (minIntensity < cost) continue;
        
        if (visitedIntensity[curr] < cost) continue;
        
        // 산봉우리에 도착했다면 정답 갱신 후 탐색 종료
        if (isSummit[curr])
        {
            if (minIntensity > cost)
            {
                minIdx = curr;
                minIntensity = cost;
            }
            else if (minIntensity == cost && minIdx > curr) 
            {
                minIdx = curr;
            }
            
            continue; 
        }
        
        // 인접 노드 탐색 
        for (int k=0; k<graph[curr].size(); ++k)
        {
            const auto[newDest, newCost] = graph[curr][k];
            int tmpIntensity = max(cost, newCost); 
            
            // 새로운 경로의 intensity가 기존 기록보다 작을 때만 큐에 삽입
            if (visitedIntensity[newDest] > tmpIntensity) 
            {
                visitedIntensity[newDest] = tmpIntensity;
                pq.push({newDest, tmpIntensity});
            }
        }
    }
    
    return vector<int>({minIdx, minIntensity});
}