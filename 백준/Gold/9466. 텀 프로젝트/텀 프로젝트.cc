#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> student;
vector<bool> visited;
vector<bool> finished;
int t, n, cnt;

void dfs(int start) {
    visited[start] = true;
    int next = student[start];

    if (!visited[next])
        dfs(next);
    else if (!finished[next]) {
        for (int i = next; i != start; i = student[i])
            cnt++;
        cnt++;
    }

    finished[start] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        cnt = 0;
        student.assign(n + 1, 0);
        visited.assign(n + 1, false);
        finished.assign(n + 1, false);

        for (int i = 1; i <= n; i++)
            cin >> student[i];
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                dfs(i);
        }

        cout << n - cnt << endl;
    }

    return 0;
}