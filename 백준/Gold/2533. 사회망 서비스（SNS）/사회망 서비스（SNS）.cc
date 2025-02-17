#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graphs;
vector<bool> visited;
vector<vector<long long>> dp;
int N;

void DFS(const int& start) {
    visited[start] = true;
    dp[start][1] = 1;

    for (const auto& nxt : graphs[start]) {
        if (visited[nxt])
            continue;

        DFS(nxt);
        // 본인이 어답터라면.. 자식은 몰?루
        dp[start][1] += min(dp[nxt][0], dp[nxt][1]);
        // 본인이 어답터가 아니라면 자식은 무조건 어답터
        dp[start][0] += dp[nxt][1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    graphs.resize(N + 1);
    visited.resize(N + 1, false);
    dp.resize(N + 1, vector<long long>(2, 0));

    for (int i = 1; i < N; i++) {
        int sp, lp;
        cin >> sp >> lp;
        graphs[sp].push_back(lp);
        graphs[lp].push_back(sp);
    }

    DFS(1);

    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}