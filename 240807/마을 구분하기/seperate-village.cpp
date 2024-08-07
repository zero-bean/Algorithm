#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool in_Range(pair<int, int> pos, int max) { return pos.first >= 0 && pos.second >= 0 && pos.first < max && pos.second < max; }

void dfs(vector<vector<bool>>& grid, pair<int, int> pos, int& count) {
    if (!grid[pos.first][pos.second])
        return;

    grid[pos.first][pos.second] = false;
    count++;

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    
    for (int i = 0; i < 4; i++) {
        int nx = pos.first + dx[i];
        int ny = pos.second + dy[i];

        if (in_Range({ nx, ny }, grid.size()))
            dfs(grid, { nx, ny }, count);
    }
}

int main() {
    int N;

    cin >> N;

    vector<int> people;
    vector<vector<bool>> grid(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int count = 0;
            
            dfs(grid, { i, j }, count);

            if (count != 0)
                people.push_back(count);
        }
    }

    sort(people.begin(), people.end());

    cout << people.size() << endl;

    for (int& i : people)
        cout << i << endl;

    return 0;
}