#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int n;

void Solve() {
    vector<int> ascendingDP(n, 1);
    vector<int> descendingDP(n, 1);
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vec[i] > vec[j] && ascendingDP[i] < ascendingDP[j] + 1)
                ascendingDP[i] = ascendingDP[j] + 1;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (vec[i] > vec[j] && descendingDP[i] < descendingDP[j] + 1)
                descendingDP[i] = descendingDP[j] + 1;
        }
    }

    for (int i = 0; i < n; i++)
        maxLength = max(maxLength, ascendingDP[i] + descendingDP[i] - 1);

    cout << maxLength << endl;
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