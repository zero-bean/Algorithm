#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N = 0, K = 0;
vector<int> DP{};
vector<int> Values{};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	DP.resize(K + 1, numeric_limits<int>::max());
	DP[0] = 0;

	Values.resize(N, 0);
	for (int& Value : Values)
	{
		cin >> Value;
	}

	for (int i = 1; i <= K; ++i)
	{
		// 임의의 동전 가치 + (현재 가치 - 임의의 동전 가치)의 경우
		for (int j = 0; j < N; ++j)
		{
			int leftValue = i - Values[j];
			
			if (leftValue < 0 || DP[leftValue] == numeric_limits<int>::max())
			{
				continue;
			}

			DP[i] = min(DP[i], 1 + DP[leftValue]);
		}
	}

	DP[K] == numeric_limits<int>::max() ? cout << -1 << endl : cout << DP[K] << endl;

	return 0;
}