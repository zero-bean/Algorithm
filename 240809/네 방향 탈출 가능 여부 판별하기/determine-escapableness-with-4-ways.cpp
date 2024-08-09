#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool in_Range(int x, int y, pair<int, int> range) {
    return x >= 0 && x < range.first && y >= 0 && y < range.second;
}

void bfs(vector<vector<bool>>& grid, pair<int, int> range) {
    queue<pair<int, int>> q;
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    q.push({ 0,0 });

    while (!q.empty()) {
        pair<int, int> current_Pos = q.front();
        
        q.pop();

        grid[current_Pos.first][current_Pos.second] = false;

        for (int i = 0; i < 4; i++) {
            pair<int, int> next_Pos = { current_Pos.first + dx[i], current_Pos.second + dy[i] };

            if (in_Range(next_Pos.first, next_Pos.second, range) && grid[next_Pos.first][next_Pos.second])
                q.push(next_Pos);
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<bool>> grid(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool b;

            cin >> b;

            grid[i][j] = b;
        }
    }

    bfs(grid, { n, m });

    cout << !(grid[n - 1][m - 1]);

    return 0;
}