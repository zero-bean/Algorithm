#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos;
int N, C;

void Solve() {
    int left = 1;
    int right = pos[N - 1];
    int mid;
    int ans;

    while (left <= right) {
        mid = (left + right) / 2;
        int lastPos = pos[0];
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if (pos[i] - lastPos >= mid) {
                lastPos = pos[i];
                cnt++;
            }
        }

        if (cnt >= C) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }

    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;

    pos.resize(N);

    for (int i = 0; i < N; i++)
        cin >> pos[i];

    sort(pos.begin(), pos.end());

    Solve();

    return 0;
}
