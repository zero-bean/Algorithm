#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

int n, k;

bool in_Range(int x) {
    return x >= 0 && x <= 100000;
}

void bfs() {
    vector<bool> visited(100001, false);
    vector<int> trials(100001, numeric_limits<int>::max());
    queue<int> q;

    q.push(n);
    trials[n] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (visited[curr])
            continue;

        visited[curr] = true;

        int next[3] = { curr * 2, curr + 1, curr - 1 };
        int plus[3] = { 0,1,1 };

        for (int i = 0; i < 3; i++) {
            if (in_Range(next[i]) && trials[next[i]] > trials[curr] + plus[i]) {
                trials[next[i]] = trials[curr] + plus[i];
                q.push(next[i]);
            }
        }
    }

    cout << trials[k] << endl;
}

int main() {
    cin >> n >> k;

    bfs();

    return 0;
}