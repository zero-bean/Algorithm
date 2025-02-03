#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct graph {
    int vertex;
    int weight;

    graph(int V, int W) : vertex(V), weight(W) {};
};

struct cmp {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

void dijkstra(const vector<vector<graph>>& v, int start) {
    vector<int> dist(v.size(), numeric_limits<int>::max());
    vector<int> visited(v.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    dist[start] = 0;
    pq.push({ start, dist[start] });

    while (!pq.empty()) {
        pair<int, int> startEdge = pq.top();

        pq.pop();

        if (visited[startEdge.first])
            continue;

        visited[startEdge.first] = true;

        for (const graph& g : v[startEdge.first]) {
            if (visited[g.vertex])
                continue;

            int tmp = dist[startEdge.first] + g.weight;

            if (tmp < dist[g.vertex]) {
                dist[g.vertex] = tmp;
                pq.push({ g.vertex , tmp });
            }
        }
    }

    for (int i = 1; i < dist.size(); i++)
        dist[i] == numeric_limits<int>::max() ? cout << "INF" << "\n" : cout << dist[i] << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;

    cin >> V >> E >> K;

    vector<vector<graph>> graphs(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;

        cin >> u >> v >> w;

        graphs[u].emplace_back(v, w);
    }

    dijkstra(graphs, K);

    return 0;
}