#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int leftTime = 0;
	int priority = 0;
	vector<int> neighbors{};
};

int Solve(vector<Node> nodes)
{
	vector<int> consumeTime(nodes.size(), 0);
	int answer = 0;
	queue<int> q{};

	// 초기화
	for (int i = 1; i < nodes.size(); ++i)
	{
		if (nodes[i].priority == 0)
		{
			q.push(i);
		}
	}

	while (q.empty() == false)
	{
		const int currIdx = q.front();
		q.pop();

		nodes[currIdx].priority = -1;

		for (int i = 0; i < nodes[currIdx].neighbors.size(); ++i)
		{
			const int nxtIdx = nodes[currIdx].neighbors[i];

			consumeTime[nxtIdx] = max(consumeTime[nxtIdx], consumeTime[currIdx] + nodes[currIdx].leftTime);
			nodes[nxtIdx].priority -= 1;

			if (nodes[nxtIdx].priority == 0)
			{
				q.push(nxtIdx);
			}

		}

		answer = max(answer, consumeTime[currIdx] + nodes[currIdx].leftTime);
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<Node> nodes{};
	int N = 0;

	cin >> N;

	nodes.resize(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		int consumeTime = 0;
		int predecessorCnt = 0;
		int priority = 0;
		
		cin >> consumeTime >> predecessorCnt;

		for (int j = 0, senior = 0; j < predecessorCnt; ++j)
		{
			cin >> senior;
			nodes[senior].neighbors.push_back(i);
			priority = predecessorCnt;
		}

		nodes[i].leftTime = consumeTime;
		nodes[i].priority = priority;
	}

	cout << Solve(nodes) << endl;

	return 0;
}