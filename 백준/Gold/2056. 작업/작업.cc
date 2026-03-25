#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

struct Node
{
	int duration = 0;       // 작업 소요 시간
	int inDegree = 0;       // 선행 작업 수
	vector<int> nextNodes;  // 이 작업이 끝나야 시작할 수 있는 다음 작업들
};

int Solve(vector<Node> nodes) 
{
	vector<int> startTime(nodes.size(), 0); // 각 작업이 시작할 수 있는 가장 빠른 시간
	int totalTime = 0;
	queue<int> q;

	// 1. 선행 작업이 없는 노드들을 큐에 삽입
	for (int i = 1; i < nodes.size(); ++i)
	{
		if (nodes[i].inDegree == 0)
		{
			q.push(i);
		}
	}

	// 2. 위상 정렬
	while (!q.empty())
	{
		int currIdx = q.front();
		q.pop();

		// 현재 작업이 끝나는 시간 계산 및 최종 정답 갱신
		int currEndTime = startTime[currIdx] + nodes[currIdx].duration;
		totalTime = max(totalTime, currEndTime);

		for (int nxtIdx : nodes[currIdx].nextNodes)
		{
			// 다음 작업의 시작 가능 시간 갱신
			startTime[nxtIdx] = max(startTime[nxtIdx], currEndTime);

			// 선행 작업이 하나 끝났으므로 진입차수 감소
			nodes[nxtIdx].inDegree--;

			// 진입차수가 0이면 큐에 삽입
			if (nodes[nxtIdx].inDegree == 0)
			{
				q.push(nxtIdx);
			}
		}
	}

	return totalTime;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	vector<Node> nodes(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		int duration = 0;
		int predecessorCnt = 0;

		cin >> duration >> predecessorCnt;

		for (int j = 0; j < predecessorCnt; ++j)
		{
			int senior = 0;
			cin >> senior;
			nodes[senior].nextNodes.push_back(i);
		}

		nodes[i].duration = duration;
		nodes[i].inDegree = predecessorCnt;
	}

	cout << Solve(nodes) << "\n";

	return 0;
}