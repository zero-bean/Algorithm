#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>matrixA;
vector<vector<int>>matrixB;
vector<vector<int>>matrixR;
int N, M, K;

void solve() {
	matrixR.resize(N, vector<int>(K, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < K; x++) {
			for (int i = 0; i < M; i++)
				matrixR[y][x] += matrixA[y][i] * matrixB[i][x];
		}
	}

	for (vector<int>& v : matrixR) {
		for (int& i : v)
			cout << i << " ";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	matrixA.resize(N, vector<int>(M));
	for (vector<int>& v : matrixA) {
		for (int& i : v)
			cin >> i;
	}

	cin >> M >> K;

	matrixB.resize(M, vector<int>(K));
	for (vector<int>& v : matrixB) {
		for (int& i : v)
			cin >> i;
	}

	solve();

	return 0;
}