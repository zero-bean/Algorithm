#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> parties;
vector<int> watchers;
int N, M, P;

set<int> bfs() {
    vector<bool> visited(N + 1, false);
    set<int> sad_Cat;
    queue<int> q;

    for (const int& watcher : watchers) {
        q.push(watcher);
        visited[watcher] = true;
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (grid[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i])
            sad_Cat.insert(i);
    }

    return sad_Cat;
}

void solve() {
    set<int> sad_Cat = bfs();
    int cnt = 0;

    for (const vector<int>& party : parties) {
        bool check = true;

        for (const int& person : party) {
            if (sad_Cat.find(person) != sad_Cat.end()) {
                check = false;
                break;
            }
        }

        cnt += static_cast<int>(check);
    }

    cout << cnt << endl;
}

int main() {
    cin >> N >> M >> P;

    grid.resize(N + 1, vector<int>(N + 1, 0));

    while (P--) {
        int watcher;

        cin >> watcher;

        watchers.push_back(watcher);
    }

    for (int i = 0; i < M; i++) {
        vector<int> tmp;
        int T;

        cin >> T;

        while (T--) {
            int person;

            cin >> person;

            tmp.push_back(person);
        }

        parties.push_back(tmp);

        for (int j = 0; j < tmp.size() - 1; j++) {
            grid[tmp[j]][tmp[j + 1]] = 1;
            grid[tmp[j + 1]][tmp[j]] = 1;
        }
    }

    solve();

    return 0;
}