#include <iostream>
#include <vector>

using namespace std;

vector<int> grid;
int N, M;

void Solve() {
    vector<long long> mod(M);
    long long prefix = 0;
    long long cnt = 0;

    for (int i = 0; i < N; i++) {
        prefix += grid[i];
        mod[prefix % M]++;
    }

    for (int i = 0; i < M; i++) {
        cnt += (mod[i] * (mod[i] - 1) / 2);
    }

    cout << mod[0] + cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    grid.resize(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    Solve();

    return 0;
}
