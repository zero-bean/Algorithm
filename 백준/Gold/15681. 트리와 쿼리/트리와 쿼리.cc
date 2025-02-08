#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
    int idx = 0;
    vector<int> children{};

    Tree() : idx(0), children{} {}
    Tree(int i) : idx(i), children{} {}
};

int N = 0, R = 0, Q = 0;
vector<vector<int>> graphs = {};
vector<int> subTreeCount = {};
vector<int> querySequence = {};
vector<Tree> tree = {};

void Make_Tree(int curr, int parent) {
    for (const int& g : graphs[curr]) {
        if (g == parent)
            continue;

        tree[curr].children.push_back(g);
        Make_Tree(g, curr);
    }
}

void Count_SubTree(int curr) {
    subTreeCount[curr] = 1;

    for (const int& child : tree[curr].children) {
        Count_SubTree(child);
        subTreeCount[curr] += subTreeCount[child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;

    graphs.resize(N + 1);
    subTreeCount.resize(N + 1, 0);
    querySequence.resize(Q);
    tree.resize(N + 1);

    for (int i = 1; i <= N; i++)
        tree[i] = Tree(i);

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }

    for (int& query : querySequence)
        cin >> query;

    Make_Tree(R, 0);
    Count_SubTree(R);

    for (const int& query : querySequence)
        cout << subTreeCount[query] << "\n";

    return 0;
}