#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> game;
vector<int> item;
int n, m, r;

void Solve() {
	vector<int> values = item;
	int answer = 0;

	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (game[start][mid] == numeric_limits<int>::max() 
					|| game[mid][end] == numeric_limits<int>::max())
					continue;

				game[start][end] = min(game[start][mid] + game[mid][end], game[start][end]);
			}
		}
	}

	for (int start = 1; start <= n; start++) {
		int tmp = 0;

		for (int end = 1; end <= n; end++) {
			if (game[start][end] <= m)
				tmp += values[end];
		}

		answer = max(answer, tmp);
	}

	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	item.resize(n + 1);
	for (int i = 1; i < item.size(); i++)
		cin >> item[i];

	game.assign(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
	for (int i = 1; i <= n; i++)
		game[i][i] = 0;

	while (r--) {
		int sp, lp, cost;

		cin >> sp >> lp >> cost;

		game[sp][lp] = min(game[sp][lp], cost);
		game[lp][sp] = min(game[lp][sp], cost);
	}

	Solve();

	return 0;
}