#include <iostream>
#include <vector>

using namespace std;

void printResult(const vector<int>& v) {
    for (const int& i : v)
        cout << i << " ";
    cout << endl;

    return;
}

void recursive(vector<int> v, int pos, int k, int n) {
    if (pos == n) {
        printResult(v);
        return;
    }

    for (int i = 1; i <= k; i++) {
        v[pos] = i;
        recursive(v, pos + 1, k, n);
    }
}

int main() {
    int n, k;

    cin >> k >> n;

    vector<int> v(n);

    recursive(v, 0, k, n);

    return 0;
}