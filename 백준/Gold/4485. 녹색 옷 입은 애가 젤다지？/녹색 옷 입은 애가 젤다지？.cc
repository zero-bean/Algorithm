#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int N;

struct Node
{
	Node(const int y, const int x, const int cost) : y(y), x(x), cost(cost) {}

	bool operator>(const Node& other) const { return cost > other.cost; }

	int y = 0;
	int x = 0;
	int cost = numeric_limits<int>::max();
};

bool inline isInRange(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < N; }

int BFS(const vector<vector<int>>& grid)
{
	vector<vector<int>> dp(N, vector<int>(N, numeric_limits<int>::max()));
	priority_queue<Node, vector<Node>, greater<Node>> q;
	const int cy[4] = { 0,0,-1,1 };
	const int cx[4] = { 1,-1,0,0 };
	dp[0][0] = grid[0][0];
	q.push({ 0,0, grid[0][0]});

	while (q.empty() == false)
	{
		const Node curr = q.top();
		q.pop();

		if (curr.y == N - 1 && curr.x == N - 1)
		{
			return curr.cost;
		}
	
		for (int i = 0; i < 4; ++i)
		{
			const int ny = curr.y + cy[i];
			const int nx = curr.x + cx[i];

			if (isInRange(ny, nx) == false)
			{
				continue;
			}

			const int tmpCost = dp[curr.y][curr.x] + grid[ny][nx];
			if (tmpCost < dp[ny][nx])
			{
				dp[ny][nx] = tmpCost;
				q.push({ ny, nx, tmpCost });
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