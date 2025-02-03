#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
int N, M;

bool In_Range(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < M; }

void Solve() {
    vector<vector<int>> trials(N, vector<int>(M, N * M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    auto CmpPos = [&trials](const pair<int, int>& p1, const pair<int, int>& p2) { return trials[p1.first][p1.second] > trials[p2.first][p2.second]; };
    priority_queue <pair<int, int>, vector<pair<int, int>>, decltype(CmpPos)> pq(CmpPos);
    int dy[4] = { 1,-1,0,0 };
    int dx[4] = { 0,0,1,-1 };

    visited[0][0] = true;
    trials[0][0] = 0;
    pq.push({ 0,0 });

    while (!pq.empty()) {
        int cy = pq.top().first;
        int cx = pq.top().second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (!In_Range(ny, nx) || visited[ny][nx])
                continue;

            visited[ny][nx] = true;
            trials[ny][nx] = min(trials[ny][nx], trials[cy][cx] + grid[ny][nx]);
            pq.push({ ny, nx });
        }
    }

    cout << trials[N - 1][M - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    grid = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
            grid[i][j] = (str[j] - '0');
    }

    Solve();

    return 0;
}
