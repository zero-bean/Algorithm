#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

vector<vector<int>> Graph{};
vector<vector<int>> History{};
int N = 0, M = 0;

struct MinCmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

struct MaxCmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second < b.second;
	}
};

long long FindMinDist()
{
	vector<bool> visited(N + 1, false);
	priority_queue < pair<int, int>, vector<pair<int, int>>, MinCmp> pq;
	long long totalCost = 0;

	if (History[0][1] == 0)
	{
		pq.push({ 1, 1 });
	}
	else if (History[0][1] == 1)
	{
		pq.push({ 1, 0 });
	}

	visited[0] = true;

	while (!pq.empty())
	{
		// curr.first == 현재 지역, second = 비용
		const pair<int, int> curr = pq.top();
		pq.pop();

		if (visited[curr.first])
		{
			continue;
		}

		visited[curr.first] = true;
		totalCost += curr.second;

		for (const auto& nxt : Graph[curr.first])
		{
			if (History[curr.first][nxt] == -1)
			{
				continue;
			}

			if (visited[nxt])
			{
				continue;
			}

			if (History[curr.first][nxt] == 0)
			{
				pq.push({ nxt, 1 });
			}
			else if (History[curr.first][nxt] == 1)
			{
				pq.push({ nxt, 0 });
			}
		}
	}

	return totalCost * totalCost;
}

long long FindMaxDist()
{
	vector<bool> visited(N + 1, false);
	priority_queue < pair<int, int>, vector<pair<int, int>>, MaxCmp> pq;
	long long totalCost = 0;

	if (History[0][1] == 0)
	{
		pq.push({ 1, 1 });
	}
	else if (History[0][1] == 1)
	{
		pq.push({ 1, 0 });
	}

	visited[0] = true;

	while (!pq.empty())
	{
		// curr.first == 현재 지역, second = 비용
		const pair<int, int> curr = pq.top();
		pq.pop();

		if (visited[curr.first])
		{
			continue;
		}

		visited[curr.first] = true;
		totalCost += curr.second;

		for (const auto& nxt : Graph[curr.first])
		{
			if (History[curr.first][nxt] == -1)
			{
				continue;
			}

			if (visited[nxt])
			{
				continue;
			}

			if (History[curr.first][nxt] == 0)
			{
				pq.push({ nxt, 1 });
			}
			else if (History[curr.first][nxt] == 1)
			{
				pq.push({ nxt, 0 });
			}
		}
	}

	return totalCost * totalCost;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sp = 0, lp = 0, isDescending = 0;

	cin >> N >> M;
	Graph.resize(N + 1);
	History.resize(N + 1, vector<int>(N + 1, -1));

	cin >> sp >> lp >> isDescending;
	Graph[sp].push_back(lp);
	Graph[lp].push_back(sp);
	History[sp][lp] = isDescending;
	History[lp][sp] = isDescending;
	
	for (int i = 0; i < M; ++i)
	{
		cin >> sp >> lp >> isDescending;
		Graph[sp].push_back(lp);
		Graph[lp].push_back(sp);
		History[sp][lp] = isDescending;
		History[lp][sp] = isDescending;
	}

	long long minValue = FindMinDist();
	long long maxValue = FindMaxDist();
	cout << maxValue - minValue;

	return 0;
}