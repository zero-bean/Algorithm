#include <iostream>
#include <vector>

#define MAX 30'000'000

using namespace std;

struct graph {
public:
	int sp;
	int lp;
	int weight;

public:
	graph(int s, int l, int w) : sp(s), lp(l), weight(w) {}
};

void Solve(const vector<graph>& world, int N) {
	vector<int> cost(N + 1, MAX);
	cost[1] = 0;

	for (int trial = 1; trial < N; trial++) {
		for (int i = 0; i < world.size(); i++) {
			int from = world[i].sp;
			int to = world[i].lp;
			int weight = world[i].weight;

			if (cost[to] > cost[from] + weight)
				cost[to] = cost[from] + weight;
		}
	}

	for (int i = 0; i < world.size(); i++) {
		int from = world[i].sp;
		int to = world[i].lp;
		int weight = world[i].weight;

		if (cost[to] > cost[from] + weight) {
			cout << "YES" << endl;
			return;
		}
	}


	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int caseCounts;

	cin >> caseCounts;

	while (caseCounts--) {
		vector<graph> world;
		int N, M, W;
		int sp, lp, weight;

		cin >> N >> M >> W;


		while (M--) {
			cin >> sp >> lp >> weight;

			world.push_back(graph(sp, lp, weight));
			world.push_back(graph(lp, sp, weight));
		}

		while (W--) {
			cin >> sp >> lp >> weight;

			world.push_back(graph(sp, lp, -weight));
		}

		Solve(world, N);
	}

	return 0;
}