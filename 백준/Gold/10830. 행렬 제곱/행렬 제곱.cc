#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
int N;
long long B;
const int MOD = 1000;

vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += (A[i][k] * B[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

vector<vector<int>> matrixPower(vector<vector<int>>& matrix, long long exponent) {
    if (exponent == 1) {
        vector<vector<int>> base(N, vector<int>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                base[i][j] = matrix[i][j] % MOD;
            }
        }

        return base;
    }

    vector<vector<int>> half = matrixPower(matrix, exponent / 2);
    half = multiplyMatrix(half, half);

    if (exponent % 2 == 1)
        half = multiplyMatrix(half, grid);

    return half;
}

void solve() {
    vector<vector<int>> result = matrixPower(grid, B);

    for (const auto& row : result) {
        for (const auto& element : row)
            cout << element << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;

    grid.assign(N, vector<int>(N));

    for (vector<int>& g : grid) {
        for (int& i : g)
            cin >> i;
    }

    solve();

    return 0;
}