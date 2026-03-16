#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int N;

bool inline isInRange(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < N; }

int BFS(const vector<vector<int>>& grid)
{
	vector<vector<int>> dp(N, vector<int>(N, numeric_limits<int>::max()));
	queue<pair<int, int>> q;

	dp[0][0] = grid[0][0];
	q.push({ 0,0 });

	while (q.empty() == false)
	{
		const pair<int, int> curr = q.front();
		q.pop();

		const int cy[4] = {0,0,-1,1};
		const int cx[4] = {1,-1,0,0};
	
		for (int i = 0; i < 4; ++i)
		{
			const int ny = curr.first + cy[i];
			const int nx = curr.second + cx[i];

			if (isInRange(ny, nx) == false)
			{
				continue;
			}

			if (dp[curr.first][curr.second] + grid[ny][nx] < dp[ny][nx])
			{
				dp[ny][nx] = dp[curr.first][curr.second] + grid[ny][nx];
				q.push({ ny, nx });
			}
		}
	}

	return dp[N - 1][N - 1];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i=1; cin >> N && N != 0; ++i)
	{
		vector<vector<int>> grid(N, vector<int>(N, 0));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> grid[i][j];
			}
		}

		cout << "Problem " << i << ": " << BFS(grid) << '\n';
	}

	return 0;
}