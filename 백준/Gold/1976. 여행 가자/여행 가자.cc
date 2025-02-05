#include <iostream>
#include <vector>

using namespace std;

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

    rootA > rootB ? v[rootA] = rootB : v[rootB] = rootA;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, M = 0;
    vector<int> root = {};
    vector<int> plan = {};
    
    cin >> N >> M;

    plan = vector<int>(M, 0);
    root = vector<int>(N + 1, 0);
    for (int i = 0; i <= N; i++)
        root[i] = i;

    for (int i = 1; i <= N; i++) {
        bool able = false;

        for (int j = 1; j <= N; j++) {
            cin >> able;

            if (!able || i == j)
                continue;

            Union_Root(root, i, j);
        }
    }

    for (int i = 0; i < M; i++)
        cin >> plan[i];

    for (int i = 1; i < M; i++) {
        if (root[plan[i]] != root[plan[0]]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}