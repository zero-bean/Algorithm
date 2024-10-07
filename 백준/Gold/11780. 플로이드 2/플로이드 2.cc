#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> graphs;
vector<vector<int>> tracer;
int n, m;

void floyd_Warshall(vector<vector<int>>& cost) {
    for (int xfer = 1; xfer <= n; xfer++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][xfer] == numeric_limits<int>::max()
                    || cost[xfer][j] == numeric_limits<int>::max())
                    continue;

                if (cost[i][j] > cost[i][xfer] + cost[xfer][j]) {
                    cost[i][j] = cost[i][xfer] + cost[xfer][j];
                    tracer[i][j] = tracer[xfer][j];
                }
            }
        }
    }
}

void get_Path(int sp, int lp) {
    if (tracer[sp][lp] == -1) {
        cout << 0 << endl;
        return;
    }

    vector<int> path;

    for (int i = lp; i != -1; i = tracer[sp][i])
        path.push_back(i);

    cout << path.size() << " ";
    for (auto it = path.rbegin(); it != path.rend(); it++)
        cout << *it << " ";
    cout << endl;
}

void solve() {
    vector<vector<int>> minDist = graphs;
    floyd_Warshall(minDist);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (minDist[i][j] == numeric_limits<int>::max())
                cout << 0 << " ";
            else
                cout << minDist[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            get_Path(i, j);
    }
}

void get_Input() {
    cin >> n >> m;

    graphs.assign(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
    tracer.assign(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
        graphs[i][i] = 0;

    while (m--) {
        int sp, lp, w;

        cin >> sp >> lp >> w;

        if (graphs[sp][lp] > w) {
            graphs[sp][lp] = w;
            tracer[sp][lp] = sp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    get_Input();

    solve();

    return 0;
}