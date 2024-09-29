#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> vec;
vector<vector<int>> group;
vector<pair<int, int>> walls;
vector<pair<int, int>> roads;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;

bool in_Range(pair<int, int> p) { return p.first >= 0 && p.first < N && p.second >= 0 && p.second < M; }

int BFS(const int idx, const pair<int, int> sp) {
    queue<pair<int, int>> q;
    int cnt = 0;

    q.push(sp);
    group[sp.first][sp.second] = idx;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            pair<int, int> nxt = { curr.first + dx[i], curr.second + dy[i] };

            if (in_Range(nxt) 
                && vec[nxt.first][nxt.second] != 1 
                && group[nxt.first][nxt.second] == -1) {
                group[nxt.first][nxt.second] = idx;
                q.push(nxt);
            }
        }
    }

    return cnt;
}

void solve() {
    vector<vector<int>> ans(N, vector<int>(M, 0));
    vector<int> group_Counts;
    int group_Idx = 0;

    for (int i = 0; i < roads.size(); i++) {
        pair<int, int> curr = roads[i];

        if (group[curr.first][curr.second] == -1) {
            group_Counts.push_back(BFS(group_Idx, curr));
            group_Idx++;
        }
    }

    for (int i = 0; i < walls.size(); i++) {
        pair<int, int> curr = walls[i];
        vector<int> tmp;
        int tot = 1;

        for (int j = 0; j < 4; j++) {
            pair<int, int> nxt = { curr.first + dx[j], curr.second + dy[j] };

            if (in_Range(nxt) && vec[nxt.first][nxt.second] == 0) {
                int group_id = group[nxt.first][nxt.second];

                if (find(tmp.begin(), tmp.end(), group_id) == tmp.end()) {
                    tot += group_Counts[group_id];
                    tmp.push_back(group_id);
                }
            }
        }

        ans[curr.first][curr.second] = tot % 10;
    }

    for (const auto& v : ans) {
        for (const auto& e : v)
            cout << e;
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vec.assign(N, vector<int>(M, 0));
    group.assign(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++) {
        string str;

        cin >> str;

        for (int j = 0; j < M; j++) {
            vec[i][j] = str[j] - '0';

            if (vec[i][j] == 1)
                walls.push_back({ i,j });
            else
                roads.push_back({ i,j });
        }
    }

    solve();

    return 0;
}