#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<vector<int>> Graph{};
vector<int> consumedTimes{};
int N = 0;

int findMinValue(const int index, const vector<int>& juniors)
{
	const int sz = juniors.size();
	
	if (sz == 0)
	{
		return (consumedTimes[index] = 0);
	}

	if (consumedTimes[index] != numeric_limits<int>::max())
	{
		return consumedTimes[index];
	}

	vector<int> dp(sz, 0);
	for (int i = 0; i < sz; ++i)
	{
		const int idx = juniors[i];
		dp[i] = findMinValue(idx, Graph[idx]);
	}

	sort(dp.begin(), dp.end(), greater<int>());

	for (int i = 0; i < sz; ++i)
	{
		dp[i] += (i + 1);	
	}

	sort(dp.begin(), dp.end(), greater<int>());

	return dp[0];
}

void Solve()
{
	consumedTimes[0] = findMinValue(0, Graph[0]);

	cout << consumedTimes[0] << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	Graph.resize(N);
	consumedTimes.resize(N, numeric_limits<int>::max());

	for (int curr = 0; curr < N; ++curr)
	{
		int senior = 0;

		cin >> senior;

		if (senior == -1)
		{
			continue;
		}

		Graph[senior].push_back(curr);
	}

	Solve();

	return 0;
}