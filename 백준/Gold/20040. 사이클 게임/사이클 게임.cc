#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct graph {
	int sp;
	int lp;

	graph(int sp, int lp) : sp(sp), lp(lp) {};
};

queue<graph> graphs;
int n, m;

int find_Parent(vector<int>& group, int a) {
	if (group[a] != a)
		return find_Parent(group, group[a]);

	return group[a];
}

void union_Elements(vector<int>& group, int a, int b) {
	if (a == b)
		return;

	int rootA = find_Parent(group, a);
	int rootB = find_Parent(group, b);

	rootA < rootB ? group[rootB] = rootA : group[rootA] = rootB;
}

void solve() {
	vector<int> group(n + 1);
	bool check = true;
	int cnt = 0;

	for (int i = 0; i <= n; i++)
		group[i] = i;

	while (!graphs.empty()) {
		graph selected = graphs.front();
		graphs.pop();
		cnt++;

		int vertexA = find_Parent(group, selected.sp);
		int vertexB = find_Parent(group, selected.lp);

		if (vertexA == vertexB) {
			check = false;
			break;
		}

		union_Elements(group, vertexA, vertexB);
	}

	if (!check)
		cout << cnt << endl;
	else
		cout << 0 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int t = m;

	while (t--) {
		int sp, lp;

		cin >> sp >> lp;

		graphs.push(graph(sp, lp));
	}

	solve();

	return 0;
}