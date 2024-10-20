#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

vector<vector<int>> grid;
list<pair<int, int>> cheeses;
int n, m;

bool In_Range(const pair<int, int>& p) { return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m; }

bool Is_Melted(const pair<int, int>& p) {
	int dy[4] = { -1,1,0,0, };
	int dx[4] = { 0,0,1,-1 };
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		pair<int, int> nxt = { p.first + dy[i], p.second + dx[i] };

		if (grid[nxt.first][nxt.second] == 3)
			cnt++;
	}

	return cnt >= 2;
}

bool Can_Go(const vector<vector<bool>>& visited, const pair<int, int>& p) {
	if (!In_Range(p))
		return false;

	if (visited[p.first][p.second] || grid[p.first][p.second] == 1)
		return false;

	return true;
}

void BFS(vector<vector<bool>>& visited) {
	queue<pair<int, int>> q;
	int dy[4] = { -1,1,0,0, };
	int dx[4] = { 0,0,1,-1 };

	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pair<int, int> nxt = { curr.first + dy[i], curr.second + dx[i] };

			if (Can_Go(visited, nxt)) {
				visited[nxt.first][nxt.second] = true;
				q.push(nxt);

				if (grid[nxt.first][nxt.second] == 0)
					grid[nxt.first][nxt.second] = 3;
			}
		}
	}
}

void Solve() {
	int cnt = 1;

	while (true) {
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		BFS(visited);

		for (auto i = cheeses.begin(); i != cheeses.end(); ) {
			pair<int, int> curr = *i;
			if (Is_Melted(curr)) {
				grid[curr.first][curr.second] = 0;
				i = cheeses.erase(i);
			}
			else {
				++i;
			}
		}

		if (cheeses.empty())
			break;

		cnt++;
	}

	cout << cnt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	grid.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 1)
				cheeses.push_back({ i,j });
		}
	}

	Solve();

	return 0;
}