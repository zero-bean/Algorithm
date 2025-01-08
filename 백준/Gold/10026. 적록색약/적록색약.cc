#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> normal;
vector<vector<char>> abnormal;
int N;

bool In_Range(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < N; }

void BFS(vector<vector<bool>>& visited, vector<vector<char>>& grid, const pair<int, int> p) {
	queue<pair<int, int>> q;
	int dy[4] = { 0, 0, 1, -1 };
	int dx[4] = { 1, -1, 0, 0 };

	q.push(p);
	visited[p.first][p.second] = true;

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if (!In_Range(ny, nx) || visited[ny][nx] || grid[curr.first][curr.second] != grid[ny][nx])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}
}

void Solve() {
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	int normalCase = 0;
	int abnormalCase = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j])
				continue;

			BFS(visited, normal, { i, j });
			normalCase++;
		}
	}

	for (auto& row : visited)
		fill(row.begin(), row.end(), false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j])
				continue;

			BFS(visited, abnormal, { i, j });
			abnormalCase++;
		}
	}

	cout << normalCase << " " << abnormalCase << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	normal.resize(N, vector<char>(N));
	abnormal.resize(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> normal[i][j];

			if (normal[i][j] == 'G')
				abnormal[i][j] = 'R';
			else
				abnormal[i][j] = normal[i][j];
		}
	}

	Solve();

	return 0;
}