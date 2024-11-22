#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int N, M;

bool In_Range(const pair<int, int>& p) { return p.first >= 0 && p.first < M && p.second >= 0 && p.second < N; }

bool Can_Go(const pair<int, int>& p, const int& currValue) {
	if (!In_Range(p) || currValue <= grid[p.first][p.second])
		return false;

	return true;
}

int DFS(vector<vector<int>>& dp, const pair<int, int>& p) {
	if (p.first == M - 1 && p.second == N - 1)
		return 1;

	if (dp[p.first][p.second] != -1)
		return dp[p.first][p.second];

	dp[p.first][p.second] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = p.first + dy[i];
		int nx = p.second + dx[i];

		if (!Can_Go({ ny, nx }, grid[p.first][p.second]))
			continue;

		dp[p.first][p.second] += DFS(dp, {ny, nx});
	}

	return dp[p.first][p.second];
}

void Solve() {
	vector<vector<int>> dp(M, vector<int>(N, -1));

	dp[0][0] = DFS(dp, {0, 0});
	
	cout << dp[0][0] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	grid.assign(M, vector<int>(N, 0));

	for (auto& g : grid) {
		for (auto& e : g)
			cin >> e;
	}

	Solve();

	return 0;
}