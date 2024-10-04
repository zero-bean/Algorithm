#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

struct graph {
    int vertex;
    int weight;

    graph(int v, int w) : vertex(v), weight(w) {}
};

struct cmpQ {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

vector<vector<graph>> graphs;
vector<int> tracer;
pair<int, int> dest;
int n, m;

vector<int> get_City_Order() {
    vector<int> paths;

    for (int i = dest.second; i != -1; i = tracer[i])
        paths.push_back(i);

    reverse(paths.begin(), paths.end());

    return paths;
}

vector<int> dijkstra() {
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmpQ> q;

    dist[dest.first] = 0;
    tracer[dest.first] = -1;
    q.push({ dest.first, dist[dest.first] });

    while (!q.empty()) {
        pair<int, int> curr = q.top();
        q.pop();

        if (visited[curr.first])
            continue;

        visited[curr.first] = true;

        for (const auto& nxt : graphs[curr.first]) {
            if (visited[nxt.vertex])
                continue;

            int nxtWeight = dist[curr.first] + nxt.weight;

            if (nxtWeight < dist[nxt.vertex]) {
                q.push({ nxt.vertex, nxtWeight });
                dist[nxt.vertex] = nxtWeight;
                tracer[nxt.vertex] = curr.first;
            }
        }
    }

    return dist;
}

void get_Input() {
    cin >> n >> m;

    graphs.resize(n + 1);
    tracer.resize(n + 1);

    while (m--) {
        int sp, lp, w;

        cin >> sp >> lp >> w;

        graphs[sp].push_back(graph(lp, w));
    }

    cin >> dest.first >> dest.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    get_Input();

    vector<int> distances = dijkstra();
    vector<int> paths = get_City_Order();

    cout << distances[dest.second] << endl;
    cout << paths.size() << endl;
    for (const auto& a : paths)
        cout << a << " ";
    cout << endl;

    return 0;
}