#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> v;
int n, ans = 1;

bool can_Go(int x, int y, int value, int v2) {
    return (x >= 0 && x < n && y >= 0 && y < n) && (grid[x][y] > value) && v[x][y] < v2 + 1;
}

void find_Max(int x, int y) {
    ans = max(ans, v[x][y]);

    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (can_Go(nx, ny, grid[x][y], v[x][y])) {
            v[nx][ny] = max(1 + v[x][y], v[x][y]);
            find_Max(nx, ny);
        }
    }
}

void solve(int x, int y) {
    vector<vector<int>> dp(n, vector<int>(n, 1));

    find_Max(x, y);
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));

    for (vector<int>& g : grid) {
        for (int& i : g)
            cin >> i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            solve(i, j);
    }

    cout << ans;

    return 0;
}