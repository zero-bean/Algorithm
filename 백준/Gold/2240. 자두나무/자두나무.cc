#include <iostream>
#include <vector>

using namespace std;

int T = 0, W = 0, CurrNum = 1;
vector<vector<int>> DP{};
vector<int> Tree{};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T >> W;

	Tree.resize(T + 1, 0);
	for (int i = 1; i <= T; ++i)
	{
		cin >> Tree[i];
	}

	// [시간][횟수]
	DP.resize(T + 1, vector<int>(W + 1, 0));
	
	// 나무 1에서 시작한 경우
	for (int i = 1; i <= T; ++i)
	{
		DP[i][0] = DP[i-1][0] + (Tree[i] == 1);
	}

	// i는 횟수, j는 시간
	for (int i = 1; i <= W; ++i)
	{
		i % 2 == 0 ? CurrNum = 1 : CurrNum = 2;

		for (int j = 1; j <= T; ++j)
		{
			DP[j][i] = max(DP[j - 1][i], DP[j - 1][i - 1]) + (Tree[j] == CurrNum);
		}
	}

	int answer = 0;
	for (int i = 0; i <= W; ++i)
	{
		answer = max(answer, DP[T][i]);
	}

	cout << answer << endl;

	return 0;
}