#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
int n, cnt = 0;

bool In_Range(int x, int y) { return x >= 0 && y >= 0 && x <= n && y <= n; }

bool Can_Go(int x, int y) {
	if (!In_Range(x, y) || grid[x][y] == 1)
		return false;

	return true;
}

void DFS(int x, int y, int mode) {
	if (x == n && y == n) {
		cnt++;
		return;
	}

	int dx[3] = { 0, 1, 1 };
	int dy[3] = { 1, 0, 1 };


	if (mode != 1 && Can_Go(x + dx[0], y + dy[0]))
		DFS(x + dx[0], y + dy[0], 0);

	if (mode != 0 && Can_Go(x + dx[1], y + dy[1]))
		DFS(x + dx[1], y + dy[1], 1);

	if (Can_Go(x + dx[0], y + dy[0])
		&& Can_Go(x + dx[1], y + dy[1])
		&& Can_Go(x + dx[2], y + dy[2]))
		DFS(x + dx[2], y + dy[2], 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	grid.assign(n+1, vector<int>(n+1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> grid[i][j];
	}

	if (grid[n][n] == 1) {
		cout << 0 << endl;
		return 0;
	}

	DFS(1, 2, 0);

	cout << cnt << endl;

	return 0;
}