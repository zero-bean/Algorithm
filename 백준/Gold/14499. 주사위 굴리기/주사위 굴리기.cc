#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0, M = 0, X = 0, Y = 0, K = 0;
vector<vector<int>> Board{};
vector<int> Turns{};
vector<int> Dice(6, 0);

bool IsInRange(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < M; }

void GenerateNextCoordinate(const int idx, int& outY, int& outX)
{
	// 1 == 우, 2 == 좌, 3 == 북, 4 == 남
	if (Turns[idx] == 1)
	{
		outX += 1;
	}
	else if (Turns[idx] == 2)
	{
		outX -= 1;
	}
	else if (Turns[idx] == 3)
	{
		outY -= 1;
	}
	else if (Turns[idx] == 4)
	{
		outY += 1;
	}
}

void UpdateDice(const int idx)
{
	vector<int> tmp(4, 0);
	vector<int> indices(4, 0);

	// 0 == 뒤, 1 == 천장, 2 == 앞, 3 == 바닥, 4 == 좌측, 5 == 우측

	if (Turns[idx] == 1) // 우
	{
		indices = { 1, 5, 3, 4 };
		tmp = { Dice[4], Dice[1], Dice[5], Dice[3] };
	}
	else if (Turns[idx] == 2) // 좌
	{
		indices = { 1, 4, 3, 5 };
		tmp = { Dice[5], Dice[1], Dice[4], Dice[3] };
	}
	else if (Turns[idx] == 3) // 위
	{
		indices = { 1, 0, 3, 2 };
		tmp = { Dice[2], Dice[1], Dice[0], Dice[3] };
	}
	else if (Turns[idx] == 4) // 아래
	{
		indices = { 1, 2, 3, 0 };
		tmp = { Dice[0], Dice[1], Dice[2], Dice[3] };
	}

	for (int i = 0; i < 4; ++i)
	{
		Dice[indices[i]] = tmp[i];
	}

	if (Board[Y][X] == 0)
	{
		Board[Y][X] = Dice[3];
	}
	else
	{
		Dice[3] = Board[Y][X];
		Board[Y][X] = 0;
	}

	cout << Dice[1] << "\n";
}

void Solve()
{
	// Dice
	// 0 == 천장 위, 1 == 천장, 2 == 천장 아래, 3 == 바닥, 4 == 좌측, 5 == 우측
	for (int i = 0; i < K; ++i)
	{
		int ny = Y, nx = X;
	
		// 다음 좌표 예측
		GenerateNextCoordinate(i, ny, nx);
		
		// 이탈할 경우 명령 무시
		if (IsInRange(ny, nx) == false)
		{
			continue;
		}

		// 좌표 갱신
		Y = ny;
		X = nx;

		UpdateDice(i);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> Y >> X >> K;

	Board.resize(N, vector<int>(M, 0));
	for (vector<int>& row : Board)
	{
		for (int& col : row)
		{
			cin >> col;
		}
	}

	// 1 == 우, 2 == 좌, 3 == 북, 4 == 남
	Turns.resize(K, 0);
	for (int& turn : Turns)
	{
		cin >> turn;
	}

	Solve();

	return 0;
}