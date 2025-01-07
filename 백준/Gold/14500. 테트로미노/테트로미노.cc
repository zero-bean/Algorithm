#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
int N, M;

bool In_Range(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < M; }

int Calculate_Score(const vector<pair<int, int>>& shape, const int y, const int x) {
    int score = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + shape[i].first;
        int nx = x + shape[i].second;

        if (In_Range(ny, nx) == false)
            return 0;

        score += grid[ny][nx];
    }

    return score;
}

void Solve() {
    vector<vector<pair<int, int>>> shapes = {
        // I 모양
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
        // O 모양
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
        // L 모양
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},  
        {{0, 0}, {1, 0}, {0, 1}, {0, 2}},  
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},  
        {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
        {{2, 0}, {2, 1}, {1, 1}, {0, 1}},   
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, 
        {{0, 0}, {0, 1}, {1, 0}, {2, 0}},  
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, 
        // Z 모양
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
        {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        // T 모양
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
        {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
        {{0, 0}, {1, 0}, {2, 0}, {1, 1}}
    };
    int maxScore = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (const auto& shape : shapes) {
                maxScore = max(maxScore, Calculate_Score(shape, i, j));
            }
        }
    }

    cout << maxScore << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    grid.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    }

    Solve();

    return 0;
}