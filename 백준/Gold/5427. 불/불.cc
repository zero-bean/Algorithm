#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<vector<char>> building{};
int T = 0, Cols = 0, Rows = 0;

bool inline isInRange(const int y, const int x) { return y >= 0 && y < Cols && x >= 0 && x < Rows; }

void logFire(vector<vector<int>>& record, queue<pair<int, int>>& pos)
{
	vector<vector<bool>> visited(Cols, vector<bool>(Rows, false));

	while (!pos.empty())
	{
		int cy[4] = {0,0,1,-1};
		int cx[4] = {1,-1,0,0};

		const pair<int, int> curr = pos.front();
		pos.pop();

		visited[curr.first][curr.second] = true;

		for (int i = 0; i < 4; ++i)
		{
			int ny = curr.first + cy[i];
			int nx = curr.second + cx[i];

			if (isInRange(ny, nx) == false)
			{
				continue;
			}

			if (visited[ny][nx])
			{
				continue;
			}

			visited[ny][nx] = true;

			if (building[ny][nx] == '#')
			{
				continue;
			}

			record[ny][nx] = min(record[ny][nx], record[curr.first][curr.second] + 1);
			pos.push({ ny, nx });
		}
	}
}

int logPerson(vector<vector<int>>& record, const vector<vector<int>>& recordedFire, queue<pair<int, int>>& pos)
{
	vector<vector<bool>> visited(Cols, vector<bool>(Rows, false));

	while (!pos.empty())
	{
		int cy[4] = { 0,0,1,-1 };
		int cx[4] = { 1,-1,0,0 };

		const pair<int, int> curr = pos.front();
		pos.pop();

		visited[curr.first][curr.second] = true;

		for (int i = 0; i < 4; ++i)
		{
			int ny = curr.first + cy[i];
			int nx = curr.second + cx[i];

			if (isInRange(ny, nx) == false)
			{
				return record[curr.first][curr.second] + 1;
			}

			if (visited[ny][nx])
			{
				continue;
			}

			visited[ny][nx] = true;

			if (building[ny][nx] == '#' || recordedFire[ny][nx] <= record[curr.first][curr.second] + 1)
			{
				continue;
			}

			record[ny][nx] = min(record[ny][nx], record[curr.first][curr.second] + 1);
			pos.push({ ny, nx });
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> Rows >> Cols;

		building.assign(Cols, vector<char>(Rows, '#'));
		vector<vector<int>> fire(Cols, vector<int>(Rows, numeric_limits<int>::max()));
		vector<vector<int>> person(Cols, vector<int>(Rows, numeric_limits<int>::max()));
		queue<pair<int, int>> firePos{};
		queue<pair<int, int>> personPos{};

		for (int i = 0; i < Cols; ++i)
		{
			for (int j = 0; j < Rows; ++j)
			{
				cin >> building[i][j];
			
				if (building[i][j] == '*')
				{
					firePos.push({ i,j });
					fire[i][j] = 0;
				}
				else if (building[i][j] == '@')
				{
					personPos.push({ i,j });
					person[i][j] = 0;
				}
			}
		}

		logFire(fire, firePos);
		int answer = logPerson(person, fire, personPos);

		if (answer == -1)
		{
			cout << "IMPOSSIBLE" << "\n";
		}
		else
		{
			cout << answer << "\n";
		}
	
	}

	return 0;
}