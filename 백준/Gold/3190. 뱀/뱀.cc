#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<vector<int>> board;
queue<pair<int, char>> movings;
int N, K, L;

bool In_Range(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < N; }

bool Can_Go(const int y, const int x) { return In_Range(y, x) && board[y][x] != 2; }

void Change_Direction(int& dir, const char turn) {
    if (turn == 'D')
        dir = (dir + 1) % 4;
    else
        dir = (dir - 1 + 4) % 4;
}

void Solve() {
    deque<pair<int, int>> snake;
    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };
    int ny = 0, nx = 0;
    int dir = 0;
    int time = 0;

    snake.push_back({ 0, 0 });

    while (true) {
        time++;

        ny = snake.front().first + dy[dir];
        nx = snake.front().second + dx[dir];

        if (!Can_Go(ny, nx)) 
            break;

        if (board[ny][nx] == 0) {
            pair<int, int> tail = snake.back();
            snake.pop_back();
            board[tail.first][tail.second] = 0;
        }

        snake.push_front({ ny, nx });
        board[ny][nx] = 2;

        if (!movings.empty() && movings.front().first == time) {
            Change_Direction(dir, movings.front().second);
            movings.pop();
        }
    }

    cout << time << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    board.resize(N, vector<int>(N, 0));

    board[0][0] = 2;
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = 1;
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        movings.push({ time, dir });
    }

    Solve();

    return 0;
}