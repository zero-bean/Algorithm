#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct graph {
    int vertex;
    int weight;

    graph(int v, int w) : vertex(v), weight(w) {};
};

vector<vector<graph>> graphs;
vector<bool> visited;
int n;

void dfs(vector<bool>& visited, int curr, int d, int& dist, int& max_Vertex) {
    if (visited[curr])
        return;

    visited[curr] = true;

    for (int i = 0; i < graphs[curr].size(); i++) {
        int next = graphs[curr][i].vertex;
        int next_Weight = d + graphs[curr][i].weight;

        if (!visited[next]) {
            if (next_Weight > dist) {
                max_Vertex = next;
                dist = next_Weight;
            }

            dfs(visited, next, next_Weight, dist, max_Vertex);
        }
    }
}

void solve() {
    int max_Vertex[2] = { 1, };
    int value[2] = { 0, };

    dfs(visited, 1, 0, value[0], max_Vertex[0]);
    fill(visited.begin(), visited.end(), false);
    dfs(visited, max_Vertex[0], 0, value[1], max_Vertex[1]);

    cout << value[1] << endl;
}

int main() {
    cin >> n;

    visited.resize(n + 1, false);
    graphs.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int p, c, w;

        cin >> p >> c >> w;

        graphs[p].push_back(graph(c, w));
        graphs[c].push_back(graph(p, w));
    }

    solve();

    return 0;
}