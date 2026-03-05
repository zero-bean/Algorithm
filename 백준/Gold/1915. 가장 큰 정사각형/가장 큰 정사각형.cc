#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> Grid{};
vector<vector<int>> DP{};
int N = 0, M = 0, MaxSquareSize = 0;

bool inline IsInRange(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < M; }

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	Grid.resize(N, vector<int>(M, 0));
	DP.assign(N, vector<int>(M, 1));

	for (int i = 0; i < N; ++i)
	{
		string tmp;

		cin >> tmp;

		int sz = tmp.size();
		for (int k = 0; k < sz; ++k)
		{
			Grid[i][k] = tmp[k] - '0';

			if (Grid[i][k] == 0)
			{
				DP[i][k] = 0;
			}

		}
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (y == 0 || x == 0)
			{
				MaxSquareSize = max(MaxSquareSize, Grid[y][x]);
			}

			if (!(IsInRange(y, x-1) && IsInRange(y-1, x) && IsInRange(y-1, x-1)))
			{
				continue;
			}

			if (Grid[y][x] == 0)
			{
				continue;
			}

			int minValue = min(Grid[y-1][x], min(Grid[y][x-1], Grid[y-1][x-1])) + 1;
			Grid[y][x] = minValue;
			MaxSquareSize = max(minValue, MaxSquareSize);
		}
	}

	cout << MaxSquareSize * MaxSquareSize;

	return 0;
}