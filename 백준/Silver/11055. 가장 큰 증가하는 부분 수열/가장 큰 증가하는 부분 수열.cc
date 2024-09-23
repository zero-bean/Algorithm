#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int n;

void Solve() {
    vector<int> DP(n, 0);
    int tmp = 0, maxIdx = 0;

    for (int i = 0; i < n; i++)
        DP[i] = vec[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vec[i] > vec[j] && DP[i] < DP[j] + vec[i]) {
                DP[i] = DP[j] + vec[i];
            }
        }
    }

    for (int idx = 0; idx < n; idx++) {
        if (tmp < DP[idx]) {
            tmp = DP[idx];
            maxIdx = idx;
        }
    }

    cout << DP[maxIdx] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vec.assign(n, 0);

    for (int& i : vec)
        cin >> i;

    Solve();

    return 0;
}