#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& v, vector<bool>& visited, int start, int& count) {
    visited[start] = true;

    for (int i=0; i<v[start].size(); i++) {
        int next = v[start][i];
        if (!visited[next] ) {
            visited[next] = true;
            count++;
            dfs(v, visited, next, count);
        }
    }
}

int main() {
    int N, M, count = 0;

    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<bool> visited(N+1, false);

    while (M--) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(graph, visited, 1, count);

    cout << count;

    return 0;
}