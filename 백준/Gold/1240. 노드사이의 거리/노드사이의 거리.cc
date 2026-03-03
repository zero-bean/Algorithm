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
vector<bool> Visited{};

bool DFS(const int InCurrent, const int& InLast, int& TotalDist)
{
	if (InCurrent == InLast)
	{
		return true;
	}

	vector<Node> CurrNode = Nodes[InCurrent];
	for (int i = 0; i < CurrNode.size(); ++i)
	{
		int Next = CurrNode[i].Num;
		if (Visited[Next] == true)
		{
			continue;
		}

		Visited[Next] = true;
		TotalDist += CurrNode[i].Dist;

		if (DFS(Next, InLast, TotalDist))
		{
			return true;
		}

		TotalDist -= CurrNode[i].Dist;
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	Nodes.resize(N + 1);
	Visited.resize(N + 1);

	for (int i = 1; i < N; ++i)
	{
		int start = 0, last = 0, dist = 0;
		cin >> start >> last >> dist;

		Nodes[start].push_back(Node(last, dist));
		Nodes[last].push_back(Node(start, dist));
	}

	for (int i = 0; i < M; ++i)
	{
		fill(Visited.begin(), Visited.end(), false);
		int start = 0, last = 0, totalDist = 0;

		cin >> start >> last;

		Visited[start] = true;
		DFS(start, last, totalDist);
		cout << totalDist << "\n";
	}

	return 0;
}