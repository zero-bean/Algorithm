#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Node
{
public:
	Node(const int InIndex, const int InClipboard, const int InTime) : Index(InIndex), Clipboard(InClipboard), Time(InTime) {}

	int Index = 0;
	int Clipboard = 0;
	int Time = 0;
};

int S;
vector<vector<bool>> Visited{};

int Solve()
{
	queue<Node> q;
	q.push({ 2, 1, 2 });
	
	while (!q.empty())
	{
		const Node current = q.front();
		q.pop();

		if (current.Index == S)
		{
			return current.Time;
		}

		Node next[3] = { 
			{ current.Index + current.Clipboard, current.Clipboard, current.Time + 1 }, 
			{ current.Index - 1, current.Clipboard, current.Time + 1 } ,
			{ current.Index, current.Index, current.Time + 1 } };
		
		for (int i = 0; i < 3; ++i)
		{
			if (next[i].Index > S || next[i].Index <= 1)
			{
				continue;
			}

			if (Visited[next[i].Index][next[i].Clipboard])
			{
				continue;
			}

			q.push(next[i]);
			Visited[next[i].Index][next[i].Clipboard] = true;
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	Visited.resize(S + 1, vector<bool>(S + 1, false)); // col: 인덱스, row: 클립보드

	// Visited[0][N] ~ Visited[2][N]은 이미 방문 처리
	for (int col = 0; col <= 2; ++col)
	{
		for (int row = 0; row <= S; ++row)
		{
			Visited[col][row] = true;
		}
	}

	cout << Solve();

	return 0;
}