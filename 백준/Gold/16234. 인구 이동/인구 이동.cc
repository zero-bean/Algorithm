#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> countries;
int N, L, R;

bool In_Range(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < N; }

bool BFS(vector<vector<bool>>& visited, const int y, const int x) {
    vector<pair<int, int>> confederation;
    queue<pair<int, int>> q;
    int dy[4] = { -1, 1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };
    int tot = 0;

    visited[y][x] = true;
    tot += countries[y][x];
    confederation.push_back({ y, x });
    q.push({ y, x });

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (!In_Range(ny, nx) || visited[ny][nx])
                continue;

            int gap = abs(countries[ny][nx] - countries[cy][cx]);

            if (gap >= L && gap <= R) {
                confederation.push_back({ ny, nx });
                visited[ny][nx] = true;
                tot += countries[ny][nx];
                q.push({ ny, nx });
            }
        }
    }

    if (confederation.size() == 1) 
        return false;

    int new_population = tot / confederation.size();
    for (auto& pos : confederation)
        countries[pos.first][pos.second] = new_population;

    return true;
}


void Solve() {
    int day = 0;

    while (true) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        bool check = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j])
                    continue;

                if (BFS(visited, i, j))
                    check = true;
            }
        }

        if (!check)
            break;

        day++;
    };

    cout << day << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    countries.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> countries[i][j];
    }

    Solve();

    return 0;
}