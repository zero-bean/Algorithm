#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

struct Node
{
	Node(const int inIdx, const int inValue) : index(inIdx), value(inValue) {}

	bool operator< (const Node& other) const
	{
		if (value == other.value)
		{
			return index > other.index;
		}

		return value > other.value;
	}

	int index = 0;
	int value = 0;
};

priority_queue < Node, vector<Node>> pq{};
vector<int> history{};
int N = 0, M = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	history.resize(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> history[i];
		pq.push({ i, history[i] });
	}

	cin >> M;

	while (M--)
	{
		int turn = 0;
		cin >> turn;

		if (turn == 2)
		{
			Node lowestNode = pq.top();
			
			while (lowestNode.value != history[lowestNode.index])
			{
				pq.pop();
				lowestNode = pq.top();
			}

			cout << lowestNode.index << "\n";
		}
		else if (turn == 1)
		{
			int idx = 0, changedValue = 0;
			
			cin >> idx >> changedValue;

			history[idx] = changedValue;
			pq.push({ idx, changedValue });
		}
	}

	return 0;
}