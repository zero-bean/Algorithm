#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> lab;
vector<pair<int, int>> space;
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;
vector<vector<pair<int, int>>> cases;
int n, m;

void generate_Combination(vector<pair<int, int>>& tmp, int idx) {
    if (tmp.size() == 3) {
        cases.push_back(tmp);
        return;
    }

    if (idx >= space.size())
        return;

    tmp.push_back(space[idx]);
    generate_Combination(tmp, idx + 1);
    tmp.pop_back();
    generate_Combination(tmp, idx + 1);
}

bool can_Move(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

int bfs(const vector<pair<int, int>>& walls) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> copy = lab;
    queue<pair<int, int>> q;
    int cnt = 0;

    for (const pair<int, int>& w : walls)
        copy[w.first][w.second] = 1;

    for (const pair<int, int>& v : virus)
        q.push(v);

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        int dx[4] = { -1,1,0,0 };
        int dy[4] = { 0,0,1,-1 };

        q.pop();

        if (visited[curr.first][curr.second])
            continue;

        visited[curr.first][curr.second] = true;
        cnt++;

        for (int i = 0; i < 4; i++) {
            pair<int, int> nxt = { curr.first + dx[i], curr.second + dy[i] };

            if (!can_Move(nxt.first, nxt.second))
                continue;

            if (copy[nxt.first][nxt.second] != 1) {
                copy[nxt.first][nxt.second] = 2;
                q.push(nxt);
            }
        }
    }
    
    return (n * m) - (wall.size() + 3) - cnt;
}

void solve() {
    vector<pair<int, int>> tmp;
    int ans = -1;
    
    generate_Combination(tmp, 0);

    for (const vector<pair<int, int>> c : cases)
        ans = max(ans, bfs(c));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    lab.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];

            if (lab[i][j] == 0)
                space.emplace_back(i, j);
            else if (lab[i][j] == 1)
                wall.emplace_back(i, j);
            else if (lab[i][j] == 2)
                virus.emplace_back(i, j);
        }
    }

    solve();

    return 0;
}