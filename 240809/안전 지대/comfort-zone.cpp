#include <iostream>
#include <vector>

using namespace std;

bool in_Range(pair<int, int> pos, pair<int, int> range) {
    return pos.first >= 0 && pos.first < range.first && pos.second >= 0 && pos.second < range.second;
}

void dfs(vector<vector<bool>>& v, pair<int, int> pos, int& trial) {
    if (v[pos.first][pos.second])
        return;

    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };

    v[pos.first][pos.second] = true;
    trial++;

    for (int i = 0; i < 4; i++) {
        int nx = pos.first + dx[i];
        int ny = pos.second + dy[i];
        pair<int, int> nPos = { nx, ny };

        if (in_Range(nPos, { v.size(), v[0].size() })) {
            dfs(v, nPos, trial);
        }
    }

}

int main() {
    int N, M;
    pair<int, int> answer = { 0, 0 };

    cin >> N >> M;

    vector<vector<int>> houses(N, vector<int>(M));

    for (vector<int>& v : houses) {
        for (int& i : v)
            cin >> i;
    }

    while (true) {
        vector<vector<bool>> check(N, vector<bool>(M, false));
        int area = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (houses[i][j] <= answer.first + 1)
                    check[i][j] = true;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int trial = 0;

                dfs(check, { i,j }, trial);

                if (trial != 0)
                    area++;
            }
        }

        if (answer.second < area) {
            answer.first++;
            answer.second = area;
        }
        else {
            cout << answer.first << " " << answer.second;
            break;
        }
    }

    return 0;
}