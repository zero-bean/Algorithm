#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Ground
{
public:
	int Cell = 0;			// 해당 칸의 높이
	bool Visited = false;   // 해당 칸의 방문 여부
};

vector<vector<Ground>> Grid{};
int N = 0;
int MaxHeight = 0;
int MaxSafeZones = 0;		// 최대 안전한 영역 갯수

bool inline IsInRange(const int X, const int Y) { return X >= 0 && X < N && Y >= 0 && Y < N; }

void BFS(const pair<int, int> Position, const int Height, int& SafeZones)
{
	const int DirectionY[4] = { 1, -1, 0, 0 };
	const int DirectionX[4] = { 0, 0, 1, -1 };
	queue<pair<int, int>> WaitingList{};
	
	WaitingList.push(Position);
	Grid[Position.first][Position.second].Visited = true;

	while (!WaitingList.empty())
	{
		const pair<int, int> CurrentPosition = WaitingList.front();
		WaitingList.pop();

		for (int i = 0; i < 4; ++i)
		{
			const int NextY = DirectionY[i] + CurrentPosition.first;
			const int NextX = DirectionX[i] + CurrentPosition.second;

			// 범위가 유효하지 않으면 다음 검사
			if (IsInRange(NextX, NextY) != true)
			{
				continue;
			}

			// 이미 방문한 노드라면 다음 검사
			if (Grid[NextY][NextX].Visited)
			{
				continue;
			}

			// 물에 잠기지 않은 영역이라면 대기열에 추가
			if (Grid[NextY][NextX].Cell > Height)
			{
				WaitingList.push({ NextY, NextX });
			}

			Grid[NextY][NextX].Visited = true;
		}
	}

	SafeZones++;
}

int Solve()
{
	for (int Height = 0; Height < MaxHeight; ++Height)
	{
		int CurrenrSafeZones = 0;
		for (int i = 0; i < N; ++i)
		{
			for (Ground& Grd : Grid[i])
			{
				Grd.Visited = false;
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				// 방문하지 않았으며, 안전한 영역이라면 탐색 및 카운트 증가
				if (Grid[i][j].Visited == false && Grid[i][j].Cell > Height)
				{
					BFS({ i, j }, Height, CurrenrSafeZones);
				}
				else
				{
					Grid[i][j].Visited = true;
				}
			}
		}

		MaxSafeZones = max(MaxSafeZones, CurrenrSafeZones);
	}

	return MaxSafeZones;
}

int main(void)
{
	cin >> N;

	Grid.assign(N, vector<Ground>(N, { 0, false }));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Grid[i][j].Cell;
			MaxHeight = max(MaxHeight, Grid[i][j].Cell);
		}
	}

	cout << Solve();

	return 0;
}