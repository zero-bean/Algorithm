#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> room;
vector<pair<int, int>> cleaner;
int R, C, T;

bool In_Range(const pair<int, int> p) { return p.first >= 0 && p.first < R && p.second >= 0 && p.second < C; }

void Clean_Up() {
	pair<int, int> CCW = cleaner[0];
	pair<int, int> CW = cleaner[1];

	for (int i = CCW.first - 1; i > 0; i--)
		room[i][0] = room[i - 1][0];
	
	for (int i = 0; i < C - 1; i++)
		room[0][i] = room[0][i + 1];

	for (int i = 0; i < CCW.first; i++)
		room[i][C - 1] = room[i + 1][C - 1];

	for (int i = C - 1; i > 1; i--)
		room[CCW.first][i] = room[CCW.first][i - 1];

	room[CCW.first][1] = 0;

	for (int i = CW.first + 1; i < R - 1; i++)
		room[i][0] = room[i + 1][0];

	for (int i = 0; i < C - 1; i++)
		room[R - 1][i] = room[R - 1][i + 1];

	for (int i = R - 1; i > CW.first; i--)
		room[i][C - 1] = room[i - 1][C - 1];

	for (int i = C - 1; i > 1; i--)
		room[CW.first][i] = room[CW.first][i - 1];

	room[CW.first][1] = 0;
}

void Solve() {
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	int cnt = 0;

	while (T--) {
		vector<vector<int>> copied(R, vector<int>(C, 0));

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (room[i][j] > 0) {
					int dust = room[i][j] / 5;
					int trial = 0;

					for (int k = 0; k < 4; k++) {
						pair<int, int> nxt = { i + dy[k], j + dx[k] };

						if (In_Range(nxt) && room[nxt.first][nxt.second] != -1) {
							copied[nxt.first][nxt.second] += dust;
							trial++;
						}
					}

					room[i][j] -= dust * trial;
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				room[i][j] += copied[i][j];
		}

		Clean_Up();
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0)
				cnt += room[i][j];
		}
	}

	cout << cnt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	room.assign(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];

			if (room[i][j] == -1)
				cleaner.push_back({ i,j });
		}
	}

	Solve();

	return 0;
}