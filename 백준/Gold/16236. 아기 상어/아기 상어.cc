#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> grid;
pair<int, int> pos;
int n;

struct dis {
    int x, y, dist;
    dis(int y, int x, int dist) : x(x), y(y), dist(dist) {}
};

struct cmp_Dis {
    bool operator() (const dis& d1, const dis& d2) {
        if (d1.dist == d2.dist) {
            if (d1.y == d2.y)
                return d1.x > d2.x;

            return d1.y > d2.y;
        }

        return d1.dist > d2.dist;
    }
};

bool Can_Go(const dis& d, int lv) {
    if (d.x < 0 || d.x >= n || d.y < 0 || d.y >= n)
        return false;
    if (grid[d.y][d.x] > lv)
        return false;
    return true;
}

void Solve() {
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, -1, 0, 1 };
    int exp = 0, lv = 2, tot = 0;

    while (true) {
        queue<dis> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<dis, vector<dis>, cmp_Dis> fishes;

        q.push(dis(pos.first, pos.second, 0));
        visited[pos.first][pos.second] = true;

        while (!q.empty()) {
            dis curr = q.front();
            q.pop();

            if (grid[curr.y][curr.x] != 0 && grid[curr.y][curr.x] < lv)
                fishes.push(dis(curr.y, curr.x, curr.dist));

            for (int i = 0; i < 4; ++i) {
                dis next = dis(curr.y + dy[i], curr.x + dx[i], curr.dist + 1);

                if (!Can_Go(next, lv))
                    continue;

                if (visited[next.y][next.x])
                    continue;

                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        if (fishes.empty()) {
            cout << tot << endl;
            break;
        }

        dis fish = fishes.top();
        pos = { fish.y, fish.x };
        grid[pos.first][pos.second] = 0;
        tot += fish.dist;
        exp++;

        if (exp == lv) {
            lv++;
            exp = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    grid.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 9) {
                pos = { i, j };
                grid[i][j] = 0;
            }
        }
    }

    Solve();

    return 0;
}
