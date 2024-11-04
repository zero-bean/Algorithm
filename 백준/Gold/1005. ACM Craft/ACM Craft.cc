#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void Solve(const vector<vector<int>>& graph, vector<int> inDegree, const vector<int>& time, const int& dest) {
    vector<int> dp(inDegree.size(), 0);
    queue<int> q;

    for (int i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            dp[i] = time[i];
        }
    }


    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (const int& nxt : graph[curr]) {
            inDegree[nxt]--;

            if (inDegree[nxt] == 0)
                q.push(nxt);

            dp[nxt] = max(dp[curr] + time[nxt], dp[nxt]);
        }
    }

    cout << dp[dest] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    while (T--) {
        vector<vector<int>> graph;
        vector<int> time;
        vector<int> inDegree;
        int N, K, W;

        cin >> N >> K;

        time.assign(N + 1, 0);
        inDegree.assign(N + 1, 0);
        graph.assign(N + 1, vector<int>(0));

        for (int i = 1; i <= N; i++)
            cin >> time[i];

        while (K--) {
            int p1, p2;

            cin >> p1 >> p2;

            inDegree[p2]++;

            graph[p1].push_back(p2);
        }

        cin >> W;

        Solve(graph, inDegree, time, W);
    }

    return 0;
}