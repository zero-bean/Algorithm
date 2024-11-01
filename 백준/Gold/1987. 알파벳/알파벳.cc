#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> grid;
int R, C;

bool In_Range(const pair<int, int>& p) { return p.first >= 0 && p.first < R && p.second >= 0 && p.second < C; }

void DFS(const pair<int, int>& p, vector<bool>& alphabet, int& ans, int trial) {
	ans = max(ans, trial);

	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };

	for (int i = 0; i < 4; i++) {
		pair<int, int> nxt = { p.first + dy[i], p.second + dx[i] };

		if (!In_Range(nxt))
			continue;
		if (alphabet[grid[nxt.first][nxt.second] - 65])
			continue;

		alphabet[grid[nxt.first][nxt.second] - 65] = true;
		DFS(nxt, alphabet, ans, trial + 1);
		alphabet[grid[nxt.first][nxt.second] - 65] = false;
	}
}

void Solve() {
	vector<bool> alphabet(26, false);
	int answer = 0;

	alphabet[grid[0][0] - 65] = true;
	DFS({0,0}, alphabet, answer, 1);

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	grid.assign(R, vector<char>(C, NULL));
	
	for (int i = 0; i < R; i++) {
		string str;

		cin >> str;

		for (int j = 0; j < C; j++)
			grid[i][j] = str[j];
	}

	Solve();

	return 0;
}