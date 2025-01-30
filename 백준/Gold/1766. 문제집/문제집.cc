#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<set<int>> graph;
vector<int> orders;

void Solve() {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i < orders.size(); i++) {
        if (orders[i] == 0)
            pq.push(i);
    }

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        cout << curr << " ";

        for (const auto& a : graph[curr]) {
            orders[a]--;

            if (orders[a] == 0) {
                pq.push(a);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    orders = vector<int>(N + 1, 0);
    graph = vector<set<int>>(N + 1);

    while (M--) {
        int sp, lp;

        cin >> sp >> lp;

        orders[lp]++;
        graph[sp].insert(lp);
    }

    Solve();

    return 0;
}