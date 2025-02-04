#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph {
    int sp;
    int lp;
    int weight;
};

vector<Graph> graphs;
int N, M;

int Find_Root(vector<int>& v, const int a) {
    if (v[a] != a)
        v[a] = Find_Root(v, v[a]);

    return v[a];
}

void Union_Root(vector<int>& v, const int a, const int b) {
    if (a == b)
        return;

    int rootA = Find_Root(v, a);
    int rootB = Find_Root(v, b);

    rootA < rootB ? v[rootA] = rootB : v[rootB] = rootA;
}

void Solve() {
    vector<int> root(N + 1, 0);
    vector<Graph> MST;
    int ans = 0;
    for (int i = 0; i <= N; i++)
        root[i] = i;

    sort(graphs.begin(), graphs.end(), [](const Graph& g1, const Graph& g2) {return g1.weight < g2.weight; });

    for (const auto& g : graphs) {
        if (MST.size() >= N - 1)
            break;

        int pointA = Find_Root(root, g.sp);
        int pointB = Find_Root(root, g.lp);

        if (pointA == pointB)
            continue;

        Union_Root(root, pointA, pointB);
        MST.push_back(g);
    }

    for (const auto& g : MST)
        ans += g.weight;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        Graph tmp;

        cin >> tmp.sp >> tmp.lp >> tmp.weight;

        if (tmp.sp == tmp.lp)
            continue;

        graphs.push_back(tmp);
    }

    Solve();

    return 0;
}