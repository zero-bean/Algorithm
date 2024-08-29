#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> graphs;
int n, m, x, ans = 0;


void floyd_Warshall() {
    for (int i = 0; i <= n; i++)
        graphs[i][i] = 0;

    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                if (graphs[start][mid] != numeric_limits<int>::max() 
                    && graphs[mid][end] != numeric_limits<int>::max()
                    && graphs[start][end] > graphs[start][mid] + graphs[mid][end])
                    graphs[start][end] = graphs[start][mid] + graphs[mid][end];
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;

    graphs.resize(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
    while (m--) {
        int sp, lp, cost;

        cin >> sp >> lp >> cost;

        graphs[sp][lp] = cost;
    }

    floyd_Warshall();

    for (int i = 1; i <= n; i++)
        ans = max(ans, graphs[i][x] + graphs[x][i]);

    cout << ans << endl;

    return 0;
}