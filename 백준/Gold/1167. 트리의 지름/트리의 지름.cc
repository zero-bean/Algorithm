#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int start, int cost, int& max, int& node) {
	visited[start] = true;

	if (max < cost) {
		max = cost; // max값 갱신
		node = start;
	}

	for (int i = 0; i < graph[start].size(); i++) {
		pair<int, int> next = graph[start][i];

		if (!visited[next.first]) {
			cost += next.second;
			dfs(graph, visited, next.first, cost, max, node);
			cost -= next.second; // 백트래킹
		}
	}
}

int main() {
	int V, value = 0, node;
	cin >> V;

	vector<vector<pair<int, int>>> graph(V);
	vector<bool> visited(V, false);

	while (V--) {
		int index, input[2];

		cin >> index;

		while (true) {
			cin >> input[0];
			if (input[0] == -1) break;

			cin >> input[1];
			if (input[1] == -1) break;

			graph[index - 1].push_back({ input[0] - 1, input[1] });
		}
	}

	dfs(graph, visited, 0, 0, value, node);
	for (int i = 0; i < visited.size(); i++)
		visited[i] = false;
	dfs(graph, visited, node, 0, value, node);

	cout << value << "\n";

	return 0;
}