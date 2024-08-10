#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;

struct pos {
    int x;
    int y;

    pos() {};
    pos(int x, int y) : x(x), y(y) {};
    pos(const pos& p) : x(p.x), y(p.y) {};
};

bool in_Range(pos p, int n) {
    return p.x >= 0 && p.x < n && p.y >= 0 && p.y < n;
}

void bfs(const vvi& grid, vvi check, pos& sp) {
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int best = 0;
    pos bestPos = sp;
    queue<pos> q;

    check[sp.x][sp.y] = 1;
    q.push(sp);

    while (!q.empty()) {
        pos curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pos next = pos(curr.x + dx[i], curr.y + dy[i]);

            if (in_Range(next, grid.size()) && !check[next.x][next.y]) {
                int nNum = grid[next.x][next.y];

                check[next.x][next.y] = 1;

                if (nNum >= grid[sp.x][sp.y])
                    continue;

                q.push(next);

                if (best < grid[next.x][next.y] ||
                    (best == grid[next.x][next.y] && bestPos.x > next.x) ||
                    (best == grid[next.x][next.y] && bestPos.x == next.x && bestPos.y > next.y)) {
                    bestPos = next;
                    best = grid[next.x][next.y];
                }
            }
        }
    }

    sp = bestPos;
}

int main() {
    int n, k;
    pos sp;

    cin >> n >> k;

    vvi grid(n, vector<int>(n, 0));
    vvi check(n, vector<int>(n, 0));

    for (vector<int>& g : grid) {
        for (int& i : g)
            cin >> i;
    }

    cin >> sp.x >> sp.y;
    sp = pos(sp.x - 1, sp.y - 1);

    while (k--)
        bfs(grid, check, sp);

    cout << sp.x + 1 << " " << sp.y + 1;

    return 0;
}