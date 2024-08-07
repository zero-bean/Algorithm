#include <iostream>
#include <vector>

using namespace std;

bool in_Range(pair<int, int> pos, pair<int, int> max) {
    if (pos.first < 0 || pos.first >= max.first || pos.second < 0 || pos.second >= max.second)
        return false;

    return true;
}

bool can_Go(const vector<vector<bool>>& v, pair<int, int> pos) {
    if (!in_Range(pos, {v.size(), v[0].size()}))
        return false;

    if (!v[pos.first][pos.second])
        return false;
    
    return true;
}

void dfs(vector<vector<bool>>& v, pair<int, int> pos) {
    int dx[2] = {0, 1};
    int dy[2] = {-1, 0};

    for (int i=0; i<2; i++) {
        int nx = pos.first + dx[i];
        int ny = pos.second + dy[i];

        if (can_Go(v, {nx, ny})) {
            v[nx][ny] = false;
            dfs(v, {nx, ny});
        }
    }
}

int main() {
    int N, M;

    cin >> N >> M;

    vector<vector<bool>> grid(N, vector<bool>(M, false));

    for (vector<bool>& v : grid) {
        for (bool b : v)
            cin >> b;
    }

    grid[0][0] = false;

    dfs(grid, {0, 0});

    cout << grid[N - 1][M - 1];

    return 0;
}