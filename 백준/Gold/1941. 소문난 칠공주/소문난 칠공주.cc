#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

vector<vector<char>> Grid(5, vector<char>(5));
vector<int> Group{};
int Answer = 0;

inline int ConvertPosToIndex(const int y, const int x) { return y * 5 + x; }
inline pair<int, int> ConvertIndexToPos(const int index) { return { index / 5, index % 5 }; }

inline bool IsSomGroup(const int y, const int x) { return Grid[y][x] == 'S'; }
inline bool IsInRange(const int y, const int x) { return y >= 0 && y < 5 && x >= 0 && x < 5; }

void CheckGroup()
{
	int somPeers = 0;
	for (const int& student : Group)
	{
		pair<int, int> pos = ConvertIndexToPos(student);
		somPeers += IsSomGroup(pos.first, pos.second);
	}

	if (somPeers < 4)
	{
		return;
	}

	vector<vector<bool>> visited(5, vector<bool>(5, false));
	queue<pair<int, int>> q;
	int peers = 1;

	const pair<int, int> group0 = ConvertIndexToPos(Group[0]);
	visited[group0.first][group0.second] = true;
	q.push(group0);

	while (!q.empty())
	{
		const pair<int, int> curr = q.front();
		q.pop();

		const int cy[4] = { 0,0,1,-1 };
		const int cx[4] = { 1,-1,0,0 };

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy[i] + curr.first;
			int nx = cx[i] + curr.second;

			if (!IsInRange(ny, nx) || visited[ny][nx])
			{
				continue;
			}

			visited[ny][nx] = true;

			for (const int& studentPos : Group)
			{
				if (ConvertPosToIndex(ny, nx) == studentPos)
				{
					q.push({ ny, nx });
					peers++;
					break;
				}
			}
		}
	}

	if (peers == 7)
	{
		Answer++;
	}
}

void GenerateCombination(int index)
{
	if (Group.size() >= 7)
	{
		CheckGroup();
		return;
	}

	if (index >= 25)
	{
		return;
	}

	for (int i = index; i < 25; ++i)
	{
		Group.push_back(i);
		GenerateCombination(i + 1);
		Group.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (vector<char>& cells : Grid)
	{
		for (char& cell : cells)
		{
			cin >> cell;
		}
	}

	GenerateCombination(0);

	cout << Answer << endl;

	return 0;
}