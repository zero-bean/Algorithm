#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9, 0));
vector<pair<int, int>> blanks;

bool Check_Area(const pair<int, int> p, const int value) {
    int row = p.first;
    int col = p.second;
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = 0; i < 9; i++) {
        if (board[row][i] == value || board[i][col] == value)
            return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == value)
                return false;
        }
    }

    return true;
}

bool Solve(int idx) {
    if (idx == blanks.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }

        return true;
    }

    pair<int, int> blank = blanks[idx];

    for (int i = 1; i <= 9; i++) {
        if (!Check_Area(blank, i))
            continue;

        board[blank.first][blank.second] = i;

        if (Solve(idx + 1))
            return true;

        board[blank.first][blank.second] = 0;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0)
                blanks.push_back({ i, j });
        }
    }

    Solve(0);

    return 0;
}