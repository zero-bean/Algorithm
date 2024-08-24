#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<int> v;
int n, m;

bool check() {
    if (v.empty())
        return true;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1])
            return false;
    }

    return true;
}

void solve(int idx) {
    if (v.size() == m) {
        if (check()) {
            for (const int& i : v)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    if (idx > n)
        return;

    v.push_back(idx);
    solve(idx);
    v.pop_back();
    solve(idx + 1);
}

int main() {
    cin >> n >> m;

    solve(1);

    return 0;
}