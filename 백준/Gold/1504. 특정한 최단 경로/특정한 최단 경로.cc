#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#define MAX 1'000'000'000

using namespace std;

typedef long long ll;

struct graph {
    int vertex;
    int weight;

    graph(int v, int w) : vertex(v), weight(w) {};
};

struct compare_Graphs {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

vector<vector<graph>> graphs;
pair<int, int> target;
int N, E;

vector<int> dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare_Graphs> q;
    vector<int> dist(N + 1, MAX);
    vector<bool> visited(N + 1, false);
    
    dist[start] = 0;
    q.push({ start, dist[start]});

    while (!q.empty()) {
        pair<int, int> curr = q.top();
        q.pop();

        if (visited[curr.first])
            continue;

        visited[curr.first] = true;

        for (const graph& g : graphs[curr.first]) {
            if (dist[g.vertex] > dist[curr.first] + g.weight) {
                dist[g.vertex] = dist[curr.first] + g.weight;
                q.push({ g.vertex, dist[g.vertex]});
            }
        }
    }

    return dist;
}

void solve() {
    vector<int> dist_start = dijkstra(1);
    vector<int> dist_first = dijkstra(target.first);
    vector<int> dist_second = dijkstra(target.second);
    int ans[2];

    if (dist_start[target.first] == MAX || dist_first[target.second] == MAX || dist_second[N] == MAX ||
        dist_start[target.second] == MAX || dist_second[target.first] == MAX || dist_first[N] == MAX) {
        cout << -1 << endl;
        return;
    }

    ans[0] = dist_start[target.first] + dist_first[target.second] + dist_second[N];
    ans[1] = dist_start[target.second] + dist_second[target.first] + dist_first[N];

    cout << min(ans[0], ans[1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;

    graphs.resize(N + 1);

    while (E--) {
        int sp, lp, weight;

        cin >> sp >> lp >> weight;

        graphs[sp].push_back({ lp, weight });
        graphs[lp].push_back({ sp, weight });
    }

    cin >> target.first >> target.second;

    solve();

    return 0;
}