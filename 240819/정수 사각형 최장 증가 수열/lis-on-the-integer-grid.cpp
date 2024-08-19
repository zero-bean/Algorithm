#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> v;
int n, ans = 1;

bool can_Go(int x, int y, int value, int v2) {
    return (x >= 0 && x < n && y >= 0 && y < n) && (grid[x][y] > value) && v[x][y] < v2 + 1;
}

void find_Max() {
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < 4; i++) {
                int nx = k + dx[i];
                int ny = j + dy[i];

                if (can_Go(nx, ny, grid[k][j], v[k][j])) {
                    v[nx][ny] = max(1 + v[k][j], v[k][j]);
                    ans = max(ans, v[nx][ny]);
                }
            }

        }
    }

}

void solve() {
    v.resize(n, vector<int>(n, 1));

    find_Max();
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));

    for (vector<int>& g : grid) {
        for (int& i : g)
            cin >> i;
    }

    solve();

    cout << ans;

    return 0;
}