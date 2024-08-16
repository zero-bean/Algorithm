#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> grid;
pair<int, int> dir[9] = {
    {0, 0}, {-1, 0}, {-1, 1},
    {0, 1}, {1, 1}, {1, 0},
    {1, -1}, {0, -1}, {-1, -1}
};
int n, answer = 0;

bool in_Range(pair<int, int> pos, int i) {
    int cx = pos.first;
    int cy = pos.second;
    int nx = cx + (dir[grid[cx][cy].second].first * i);
    int ny = cy + (dir[grid[cx][cy].second].second * i);

    return (nx >= 0 && nx < n && ny >= 0 && ny < n); 
}

void generate_Combination(pair<int, int> pos, int cnt) {
    for (int i = 1; in_Range(pos, i); i++) {
        int cx = pos.first;
        int cy = pos.second;
        int nx = cx + (dir[grid[cx][cy].second].first * i);
        int ny = cy + (dir[grid[cx][cy].second].second * i);

        if (grid[cx][cy].first >= grid[nx][ny].first) {
            continue;
        }

        generate_Combination({ nx, ny }, cnt + 1);
    }

    answer = max(answer, cnt);
}

void solve(pair<int, int> sp) {
    generate_Combination(sp, 0);

    cout << answer << endl;
}

int main() {
    pair<int, int> sp;
    cin >> n;

    grid.resize(n, vector<pair<int, int>>(n));

    for (vector<pair<int, int>>& g : grid) {
        for (pair<int, int>& p : g)
            cin >> p.first;
    }

    for (vector<pair<int, int>>& g : grid) {
        for (pair<int, int>& p : g)
            cin >> p.second;
    }

    cin >> sp.first >> sp.second;

    solve({ sp.first - 1, sp.second - 1 });

    return 0;
}