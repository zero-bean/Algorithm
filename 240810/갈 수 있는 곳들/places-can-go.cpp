#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool in_Range(int x, int y, int max) {
    return x >= 0 && x < max && y >= 0 && y < max;
}

void bfs(vector<vector<bool>>& vec, pair<int, int> sp, int& ans) {
    if (vec[sp.first][sp.second])
        return;

    vec[sp.first][sp.second] = true;
    ans++;

    queue<pair<int, int>> q;
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    q.push(sp);

    while (!q.empty()) {
        pair<int, int> curr = q.front();

        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = { curr.first + dx[i], curr.second + dy[i] };

            if (in_Range(next.first, next.second, vec.size()) && !vec[next.first][next.second]) {
                vec[next.first][next.second] = true;
                ans++;
                q.push(next);
            }

        }
    }
}

int main() {
    int n, k, answer = 0;

    cin >> n >> k;

    vector<vector<bool>> grid(n, vector<bool>(n, false));
    vector<pair<int, int>> start_Points(k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool b;

            cin >> b;

            grid[i][j] = b;
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        
        cin >> a >> b;

        start_Points[i] = { a - 1, b - 1 };
    }

    for (int i = 0; i < k; i++)
        bfs(grid, start_Points[i], answer);

    cout << answer;

    return 0;
}