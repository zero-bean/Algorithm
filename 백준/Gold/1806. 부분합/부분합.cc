#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int n, m;

void solve() {
    long long sum = 0;
    int ans = 100'000;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        while (sum < m && idx < n) {
            sum += arr[idx];
            idx++;
        }

        if (sum >= m)
            ans = min(ans, idx - i);

        sum -= arr[i];
    }
    
    if (ans == 100'000)
        cout << 0 << endl;
    else
        cout << ans << endl;
}

int main() {
    cin >> n >> m;

    arr.resize(n);
    for (int& a : arr)
        cin >> a;

    solve();

    return 0;
}