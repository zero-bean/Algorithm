#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
int n, k;

bool check(const vector<int>& v, int value, int idx) {
    return !(idx >= 2 && (v[idx - 1] == value && v[idx - 2] == value));
}

void generate_Combination(vector<int>& v, int idx) {
    if (idx >= n) {
        for (const int& i : v)
            cout << i << " ";
        cout << endl;
        return;
    }

    for (int value = 1; value <= k; value++) {
        if (check(v, value, idx)) {
            v[idx] = value;
            generate_Combination(v, idx + 1);
        }
    }
}

void solve() {
    vector<int> vec(n, 0);

    generate_Combination(vec, 0);
}

int main() {
    cin >> k >> n;

    solve();

    return 0;
}