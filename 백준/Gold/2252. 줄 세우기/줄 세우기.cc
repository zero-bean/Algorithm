#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> group;
int n, m;

void Solve() {
	queue<int> q;

	for (int i = 1; i < group.size(); i++) {
		if (group[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		cout << curr << " ";

		for (const auto& nxt : graph[curr]) {
			group[nxt]--;

			if (group[nxt] == 0)
				q.push(nxt);
		}
	}

	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	graph.assign(n + 1, vector<int>(0));
	group.assign(n + 1, 0);

	while (m--) {
		int a, b;

		cin >> a >> b;

		graph[a].push_back(b);
		group[b]++;
	}

	Solve();

	return 0;
}