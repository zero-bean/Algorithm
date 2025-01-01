#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L;
vector<vector<int>> grid;

bool Can_Go(const vector<int>& line) {
    vector<bool> visited(N, false);

    for (int i = 0; i < N - 1; i++) {
        if (abs(line[i] - line[i + 1]) > 1) 
            return false;

        if (line[i] == line[i + 1]) {
            continue;
        }
        else if (line[i] > line[i + 1]) {
            for (int j = 1; j <= L; j++) {
                if (i + j >= N || visited[i + j] || line[i + 1] != line[i + j])
                    return false;

                visited[i + j] = true;
            }
        }
        else {
            for (int j = 0; j < L; j++) {
                if (i - j < 0 || visited[i - j] || line[i] != line[i - j])
                    return false;

                visited[i - j] = true;
            }
        }
    }

    return true;
}

void Solve() {
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (Can_Go(grid[i])) 
            cnt++;
    }

    for (int i = 0; i < N; i++) {
        vector<int> column(N);

        for (int j = 0; j < N; j++)
            column[j] = grid[j][i];

        if (Can_Go(column))
            cnt++;
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L;

    grid.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    }

    Solve();

    return 0;
}
