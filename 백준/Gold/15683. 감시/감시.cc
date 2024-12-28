#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grid;
vector<pair<int, int>> camera;
int N, M, ans = 65;

bool In_Range(const pair<int, int>& p) { return p.first >= 0 && p.first < N && p.second >= 0 && p.second < M; }

bool Can_Go(const pair<int, int>& p) { return (In_Range(p) && grid[p.first][p.second] != 6); }

void Check_Area(const pair<int, int>& p, int dir) {
    // 상, 우, 하, 좌
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    pair<int, int> nxt = { p.first + dy[dir], p.second + dx[dir] };

    while (Can_Go(nxt)) {
        if (grid[nxt.first][nxt.second] == 0)
            grid[nxt.first][nxt.second] = -1;

        nxt = { nxt.first + dy[dir], nxt.second + dx[dir] };
    }
}

void DFS(int idx) {
    if (idx == camera.size()) {
        int tmp = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0)
                    tmp++;
            }
        }

        ans = min(ans, tmp);
        return;
    }

    pair<int, int> curr = camera[idx];
    vector<vector<int>> backUp = grid;

    for (int i = 0; i < 4; i++) {
        if (grid[curr.first][curr.second] == 1) {
            Check_Area(curr, i);
        }
        else if (grid[curr.first][curr.second] == 2) {
            Check_Area(curr, i);
            Check_Area(curr, (i + 2) % 4);
        }
        else if (grid[curr.first][curr.second] == 3) {
            Check_Area(curr, i);
            Check_Area(curr, (i + 1) % 4);
        }
        else if (grid[curr.first][curr.second] == 4) {
            Check_Area(curr, i);
            Check_Area(curr, (i + 1) % 4);
            Check_Area(curr, (i + 3) % 4);
        }
        else if (grid[curr.first][curr.second] == 5) {
            Check_Area(curr, 0);
            Check_Area(curr, 1);
            Check_Area(curr, 2);
            Check_Area(curr, 3);
        }

        DFS(idx + 1);

        grid = backUp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    grid.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            if (grid[i][j] > 0 && grid[i][j] < 6)
                camera.push_back({ i, j });
        }
    }

    DFS(0);

    cout << ans << endl;

    return 0;
}