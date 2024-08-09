#include <iostream>
#include <vector>

using namespace std;

struct pos {
    int x;
    int y;

    pos(int x1, int y1) : x(x1), y(y1) {};
};

bool in_Range(pos p, int max) {
    return p.x >= 0 && p.x < max && p.y >= 0 && p.y < max;
}

void dfs(const vector<vector<int>>& vec, vector<vector<bool>>& check, vector<pos>& blocks, pos p, int num) {
    if (check[p.x][p.y] || vec[p.x][p.y] != num)
        return;

    check[p.x][p.y] = true;
    blocks.push_back(pos(p.x, p.y));

    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    for (int i = 0; i < 4; i++) {
        pos nPos = pos(p.x + dx[i], p.y + dy[i]);

        if (in_Range(nPos, vec.size()))
            dfs(vec, check, blocks, nPos, num);
    }
}

int main() {
    int n;
    pair<int, int> answer = { 0, 0 };

    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (vector<int>& v : vec) {
        for (int& i : v)
            cin >> i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<pos> blocks;

            dfs(vec, check, blocks, pos(i, j), vec[i][j]);

            int blockCount = blocks.size();

            if (blockCount >= 4)
                answer.first++;
            
            answer.second = max(answer.second, blockCount);
        }
    }

    cout << answer.first << " " << answer.second;

    return 0;
}