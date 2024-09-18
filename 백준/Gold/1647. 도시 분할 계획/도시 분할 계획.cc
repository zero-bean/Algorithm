#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

struct graph {
	int sp;
	int lp;
	int weight;

	graph(int sp, int lp, int w) : sp(sp), lp(lp), weight(w) {};
};

vector<graph> graphs;
int n, m;

int find_Element(vector<int>& group, int a) {
	if (group[a] != a)
		return find_Element(group, group[a]);

	return group[a];
}

void union_Element(vector<int>& group, int a, int b) {
	if (a == b)
		return;

	int rootA = find_Element(group, a);
	int rootB = find_Element(group, b);

	rootA < rootB ? group[rootB] = rootA : group[rootA] = rootB;
}

vector<graph> kruskal(int& tot) {
	vector<graph> tmp;
	vector<int> group(n + 1);

	for (int i = 1; i <= n; i++)
		group[i] = i;

	for (const auto& g : graphs) {
		if (tmp.size() == n - 1)
			break;

		int houseA = find_Element(group, g.sp);
		int houseB = find_Element(group, g.lp);

		if (houseA != houseB) {
			union_Element(group, g.sp, g.lp);
			tot += g.weight;
			tmp.push_back(g);
		}
	}

	return tmp;
}

bool sort_Graph(const graph& g1, const graph& g2) { return g1.weight < g2.weight; }

void solve() {
	sort(graphs.begin(), graphs.end(), sort_Graph);
	
	int tot = 0, lowCost = numeric_limits<int>::max();
	vector<graph> ans = kruskal(tot);

	for (int i = 0; i < ans.size(); i++)
		lowCost = min(lowCost, tot - ans[i].weight);
	
	cout << lowCost << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int sp, lp, cost;

		cin >> sp >> lp >> cost;

		graphs.push_back(graph(sp, lp, cost));
	}

	solve();

	return 0;
}