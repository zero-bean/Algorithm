#include <iostream>
#include <vector>

using namespace std;

vector<int> jump;
int n, answer = 100;

void find_Minimum_Jump(int idx, int cnt) {
    if (idx >= n - 1) {
        answer = min(cnt, answer);
        return;
    }

    for (int i=1; i<= jump[idx]; i++) {
        find_Minimum_Jump(idx + i, cnt + 1);
    }
}

void solve() {
    find_Minimum_Jump(0, 0);

    answer = (answer == 100) ? -1 : answer;

    cout << answer;
}

int main() {
    cin >> n;

    jump.resize(n);
    for(int& j : jump)
        cin >> j;

    solve();

    return 0;
}