#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> ladders;
vector<int> origin_Route;
int n, m;

vector<vector<bool>> generate_Grid(const vector<pair<int, int>>& ldr) {
    vector<vector<bool>> tmp_Grid;
    int depth = 1;

    for (const pair<int, int>& ladder : ldr)
        depth = max(depth, ladder.second);

    tmp_Grid.resize(n + 1, vector<bool>(depth + 1, false));

    for (const pair<int, int>& ladder : ldr)
        tmp_Grid[ladder.first][ladder.second] = true;

    return tmp_Grid;
}

vector<int> find_Route(const vector<pair<int, int>>& ldr) {
    vector<vector<bool>> grid = generate_Grid(ldr);
    vector<int> way;
    int depth = grid[1].size() - 1;

    for (int i = 1; i <= n; i++) {
        pair<int, int> pos = { i, 1 };

        while (true) {
            if (pos.second > depth) {
                way.push_back(pos.first);
                break;
            }

            if (pos.first != n && grid[pos.first][pos.second])
                pos.first++;
            else if (pos.first != 1 && grid[pos.first - 1][pos.second])
                pos.first--;

            pos.second++;
        }
    }

    return way;
}

bool is_The_Route(const vector<pair<int, int>>& ldr) { return find_Route(ldr) == origin_Route; }

void generate_Combination(vector<pair<int, int>>& tmp, int idx, int& answer) {
    if (is_The_Route(tmp)) {
        answer = min(tmp.size(), answer);
        return;
    }

    if (idx >= m) 
        return;

    tmp.push_back(ladders[idx]);
    generate_Combination(tmp, idx + 1, answer);
    tmp.pop_back();
    generate_Combination(tmp, idx + 1, answer);
}

void solve() {
    vector<pair<int, int>> tmp_ladders;
    int answer = (int)ladders.size();

    generate_Combination(tmp_ladders, 0, answer);
    
    cout << answer << endl;
}

int main() {
    cin >> n >> m;

    ladders.resize(m);
    for (pair<int, int>& ladder : ladders)
        cin >> ladder.first >> ladder.second;

    origin_Route = find_Route(ladders);

    solve();

    return 0;
}