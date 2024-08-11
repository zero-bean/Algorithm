#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void combination(vector<vector<pair<int, int>>>& comb, const vector<pair<int, int>>& obs, vector<pair<int, int>>& tmp, const int idx, const int max) {
    if (tmp.size() == max) {
        comb.push_back(tmp);
        return;
    }

    for (int i = idx; i < obs.size(); i++) {
        tmp.push_back(obs[i]);
        combination(comb, obs, tmp, i + 1, max);
        tmp.pop_back();
    }
}

void generate_Combination(vector<vector<pair<int, int>>>& comb, const vector<pair<int, int>>& obs, const int max) {
    vector<pair<int, int>> tmp;

    combination(comb, obs, tmp, 0, max);
}

bool in_Range(const pair<int, int>& p, const int& n) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n;
}

int bfs(vector<vector<int>>& grid, const vector<pair<int, int>>& sp) {
    int n = grid.size();
    int count = 0;

    for (const pair<int, int>& p : sp) {
        if (grid[p.first][p.second])
            continue;

        grid[p.first][p.second] = 1;
        count++;
        queue<pair<int, int>> q;
        q.push(p);

        while (!q.empty()) {
            int dx[4] = { -1,1,0,0 };
            int dy[4] = { 0,0,1,-1 };
            pair<int, int> curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                pair<int, int> next = { curr.first + dx[i], curr.second + dy[i] };

                if (in_Range(next, n) && !grid[next.first][next.second]) {
                    grid[next.first][next.second] = 1;
                    q.push(next);
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    int n, k, m, answer = 0;

    cin >> n >> k >> m;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> combinations;
    vector<pair<int, int>> starts(k);
    vector<pair<int, int>> obstacles;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1)
                obstacles.push_back({ i,j });
        }
    }

    for (pair<int, int>& p : starts) {
        cin >> p.first >> p.second;
        p.first -= 1;
        p.second -= 1;
    }

    generate_Combination(combinations, obstacles, m);

    for (int j = 0; j < combinations.size(); j++) {
        vector<vector<int>> copy = grid;

        for (const pair<int, int>& p : combinations[j])
            copy[p.first][p.second] = 0;

        answer = max(answer, bfs(copy, starts));
    }

    cout << answer;

    return 0;
}