#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int K = 0, TotalScore = 0;
vector<deque<int>> Gears(4);
vector<bool> Updated(4);

int FindLeft(const int Idx)
{
	return Gears[Idx][6];
}

int FindRight(const int Idx)
{
	return Gears[Idx][2];
}

void RotateGear(const int Idx, const int Dir)
{
	if (Dir == 1)
	{
		int tmp = Gears[Idx].back();
		Gears[Idx].pop_back();
		Gears[Idx].push_front(tmp);
	}
	else if (Dir == -1)
	{
		int tmp = Gears[Idx].front();
		Gears[Idx].pop_front();
		Gears[Idx].push_back(tmp);
	}

	Updated[Idx] = true;
}

void UpdateGears(int Idx, int Dir)
{
	if (Updated[Idx])
	{
		return;
	}

	// 현재 톱니바퀴
	int currLeft = FindLeft(Idx);
	int currRight = FindRight(Idx);
	RotateGear(Idx, Dir);

	// 왼쪽 톱니바퀴
	if (Idx - 1 >= 0)
	{
		int leftGearRightState = FindRight(Idx - 1);
		if (leftGearRightState != currLeft)
		{
			UpdateGears(Idx - 1, -Dir);
		}
	}

	// 오른쪽 톱니바퀴
	if (Idx + 1 <= 3)
	{
		int rightGearLeftState = FindLeft(Idx + 1);
		if (rightGearLeftState != currRight)
		{
			UpdateGears(Idx + 1, -Dir);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; ++i)
	{
		string GearState{};
		cin >> GearState;
		for (const char& Index : GearState)
		{
			Gears[i].push_back(Index - '0');
		}
	}

	cin >> K;

	while (K--)
	{
		int Index = 0, Direction = 0;
		fill(Updated.begin(), Updated.end(), false);
		
		cin >> Index >> Direction;

		UpdateGears(Index - 1, Direction);
	}

	for (int i = 0; i < 4; ++i)
	{
		if (Gears[i].front() == 1)
		{
			TotalScore += (1 << i);
		}
	}

	cout << TotalScore << endl;

	return 0;
}