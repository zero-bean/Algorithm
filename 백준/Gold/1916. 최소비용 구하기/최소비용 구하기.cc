#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;
pair<int, int> pos;
int n, m;

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n + 1, false);

    dist[pos.first] = 0;
    pq.push({ 0, pos.first });

    while (!pq.empty()) {
        int curr = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        if (visited[curr])
            continue;

        visited[curr] = true;

        for (const auto& edge : graph[curr]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > curr_dist + weight) {
                dist[next] = curr_dist + weight;
                pq.push({ dist[next], next });
            }
        }
    }
}

int main() {
    cin >> n >> m;

    dist.resize(n + 1, numeric_limits<int>::max());
    graph.resize(n + 1);

    while (m--) {
        int start, end, cost;

        cin >> start >> end >> cost;

        graph[start].emplace_back(end, cost);
    }

    cin >> pos.first >> pos.second;

    solve();

    cout << dist[pos.second];

    return 0;
}