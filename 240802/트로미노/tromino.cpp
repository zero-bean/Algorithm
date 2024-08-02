#include <iostream>
#include <vector>

using namespace std;

void first_Check(const vector<vector<int>>& v, int& max, int n, int m) {
    int dx[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
    int dy[2][4] = { {0, 0, -1, 1}, {-1, 1, 0, 0} };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int x1 = j + dx[0][k];
                int x2 = j + dx[1][k];
                int y1 = i + dy[0][k];
                int y2 = i + dy[1][k];

                if (x1 < 0 || x1 >= m || x2 < 0 || x2 >= m || y1 < 0 || y1 >= n || y2 < 0 || y2 >= n)
                    continue;

                int tmp = v[i][j] + v[y1][x1] + v[y2][x2];
                max = max > tmp ? max : tmp;
            }
        }
    }
}

void second_Check(const vector<vector<int>>& v, int& max, int n, int m) {
    int dx[2][4] = { {-1, 1, 0, 0}, {1, -1, 0, 0} };
    int dy[2][4] = { {0, 0, -1, 1}, {0, 0, 1, -1} };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int x1 = j + dx[0][k];
                int x2 = j + dx[1][k];
                int y1 = i + dy[0][k];
                int y2 = i + dy[1][k];

                if (x1 < 0 || x1 >= m || x2 < 0 || x2 >= m || y1 < 0 || y1 >= n || y2 < 0 || y2 >= n)
                    continue;

                int tmp = v[i][j] + v[y1][x1] + v[y2][x2];
                max = max > tmp ? max : tmp;
            }
        }
    }
}

int main() {
    int n, m, max = 0;

    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    for (vector<int>& v : vec) {
        for (int& i : v)
            cin >> i;
    }

    first_Check(vec, max, n, m);
    second_Check(vec, max, n, m);

    cout << max;

    return 0;
}