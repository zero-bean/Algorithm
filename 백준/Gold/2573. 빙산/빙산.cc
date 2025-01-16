#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
queue<pair<int, int>> ices;
int N, M;

bool In_Range(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < M; }

int Check_Melted_Ice(const int y, const int x) {
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,1,-1 };
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!In_Range(ny, nx) || grid[ny][nx] != 0)
            continue;
    
        cnt++;
    }

    return cnt;
}

void BFS(vector<vector<bool>>& visited, const pair<int, int>& p) {
    queue<pair<int, int>> q;
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,1,-1 };

    q.push(p);
    visited[p.first][p.second] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (!In_Range(ny, nx) || visited[ny][nx] || grid[ny][nx] == 0)
                continue;

            visited[ny][nx] = true;
            q.push({ ny,nx });
        }
    }
}

void Solve() {
    int years = 0;
    int areas = 0;

    while (!ices.empty()) {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        vector<vector<int>> copied_Grid = grid;
        queue<pair<int, int>> copied_Ices = ices;
        areas = 0;

        while (!copied_Ices.empty()) {
            auto ice = copied_Ices.front();
            copied_Ices.pop();

            if (!visited[ice.first][ice.second]) {
                BFS(visited, ice);
                areas++;
            }
        }

        if (areas >= 2) {
            cout << years << endl;
            return;
        }

        while (!ices.empty()) {
            auto ice = ices.front();
            ices.pop();

            int melted = Check_Melted_Ice(ice.first, ice.second);
            copied_Grid[ice.first][ice.second] = max(0, grid[ice.first][ice.second] - melted);

            if (copied_Grid[ice.first][ice.second] != 0)
                copied_Ices.push(ice);
        }

        grid = copied_Grid;
        ices = copied_Ices;
        years++;
    }

    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    grid.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            if (grid[i][j] != 0)
                ices.push({ i,j });
        }
    }

    Solve();

    return 0;
}
