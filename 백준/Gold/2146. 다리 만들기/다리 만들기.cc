#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grid;
vector<pair<int, int>> island_Pos;
int n;

bool In_Range(const pair<int, int>& p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n;
}

vector<pair<int, int>> BFS(vector<vector<bool>>& visited, const pair<int, int>& start, const int& num) {
    vector<pair<int, int>> group;
    queue<pair<int, int>> q;
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    q.push(start);
    visited[start.first][start.second] = true;
    group.push_back(start);

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> nxt = {curr.first + dy[i], curr.second + dx[i]};

            if (!In_Range(nxt) || visited[nxt.first][nxt.second])
                continue;

            if (grid[nxt.first][nxt.second] == 1) {  // 섬 내부만 탐색
                visited[nxt.first][nxt.second] = true;
                grid[nxt.first][nxt.second] = num;
                group.push_back(nxt);
                q.push(nxt);
            }
        }
    }

    return group;
}

void Solve() {
    vector<vector<pair<int, int>>> groups;
    vector<vector<bool>> visited;
    int group_Number = 2;
    int dist = 10'000;

    visited.assign(n, vector<bool>(n, false));

    for (const auto& p : island_Pos) {
        if (!visited[p.first][p.second] && grid[p.first][p.second] == 1) {
            groups.push_back(BFS(visited, p, group_Number++));
        }
    }

    for (int i = 0; i < groups.size() - 1; i++) {
        for (int j = 0; j < groups[i].size(); j++) {
            pair<int, int> p1 = groups[i][j];

            for (int k = i + 1; k < groups.size(); k++) {
                for (int m = 0; m < groups[k].size(); m++) {
                    pair<int, int> p2 = groups[k][m];

                    int tmp = abs(p2.first - p1.first) + abs(p2.second - p1.second) - 1;

                    dist = min(dist, tmp);
                }
            }
        }
    }

    cout << dist << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    grid.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1)  // 섬 좌표만 저장
                island_Pos.push_back({i, j});
        }
    }

    Solve();

    return 0;
}
