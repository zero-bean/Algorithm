#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> Dist{};
int V = 0, E = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;

	Dist.resize(V + 1, vector<int>(V + 1, numeric_limits<int>::max()));

	for (int i = 0; i < E; ++i)
	{
		int start = 0, last = 0, weight = 0;
		
		cin >> start >> last >> weight;

		if (Dist[start][last] > weight)
		{
			Dist[start][last] = weight;
		}
	}

	for (int mid = 1; mid <= V; ++mid)
	{
		for (int start = 1; start <=V; ++start)
		{
			for (int last = 1; last <= V; ++last)
			{
				if (Dist[start][mid] == numeric_limits<int>::max() || Dist[mid][last] == numeric_limits<int>::max())
				{
					continue;
				}

				Dist[start][last] = min(Dist[start][last], Dist[start][mid] + Dist[mid][last]);
			}
		}
	}

	int minimum = numeric_limits<int>::max();
	for (int i = 1; i <= V; ++i)
	{
		minimum = min(minimum, Dist[i][i]);
	}

	minimum == numeric_limits<int>::max() ? cout << -1 << endl : cout << minimum << endl;

	return 0;
}