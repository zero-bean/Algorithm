#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 

using namespace std;

int N = 0, Q = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;

	int currIdx = 1;
	vector<int> history(N + 1, 0);
	set<int> infos{};

	for (int i = 1; i <= N; ++i)
	{
		cin >> history[i];

		if (history[i] == 1)
		{
			infos.insert(i);
		}
	}

	while (Q--)
	{
		int turn = 0;

		cin >> turn;

		if (turn == 1)
		{
			int idx = 0;

			cin >> idx;

			if (history[idx] == 1)
			{
				infos.erase(idx);
				history[idx] = 0;
			}
			else
			{
				infos.insert(idx);
				history[idx] = 1;
			}

		}
		else if (turn == 2)
		{
			int move = 0;

			cin >> move;

			currIdx = (currIdx - 1 + move) % N + 1;
		}
		else if (turn == 3)
		{
			if (infos.empty())
			{
				cout << "-1\n";
			}
			else
			{
				set<int>::iterator it = infos.lower_bound(currIdx);

				if (it == infos.end())
				{
					const int nearestDist = abs(*infos.begin() - currIdx + N) % N;
					cout << nearestDist << "\n";
				}
				else
				{
					const int nearestDist = (*it - currIdx + N) % N;
					cout << nearestDist << "\n";
				}
			}
		}
	}

	return 0;
}