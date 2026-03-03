#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

struct Node
{
public:
	Node(const int InNum, const int InDist) : Num(InNum), Dist(InDist) {}

	int Num = 0;
	int Dist = 0;
};

vector<vector<Node>> Nodes{};

bool DFS(vector<bool>& InVisited, const int InCurrent, const int& InLast, int& TotalDist)
{
	if (InCurrent == InLast)
	{
		return true;
	}

	vector<Node> CurrNode = Nodes[InCurrent];
	for (int i = 0; i < CurrNode.size(); ++i)
	{
		int Next = CurrNode[i].Num;
		if (InVisited[Next] == true)
		{
			continue;
		}

		InVisited[Next] = true;
		TotalDist += CurrNode[i].Dist;

		if (DFS(InVisited, Next, InLast, TotalDist))
		{
			return true;
		}

		TotalDist -= CurrNode[i].Dist;
	}

	return false;
}

int main(void)
{
	cin >> N >> M;

	Nodes.resize(N + 1);

	for (int i = 1; i < N; ++i)
	{
		int start = 0, last = 0, dist = 0;
		cin >> start >> last >> dist;

		Nodes[start].push_back(Node(last, dist));
		Nodes[last].push_back(Node(start, dist));
	}

	for (int i = 0; i < M; ++i)
	{
		vector<bool> visited(N + 1, false);
		int start = 0, last = 0, totalDist = 0;

		cin >> start >> last;

		visited[start] = true;
		DFS(visited, start, last, totalDist);
		cout << totalDist << endl;
	}

	return 0;
}