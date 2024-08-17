#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> ans;
int value[3] = { 4, 5, 6 };
int n;

bool isValid(const vector<int>& v) {
    int size = v.size();
    for (int i = 1; i <= size / 2; i++) {
        if (equal(v.end() - i, v.end(), v.end() - 2 * i))
            return false;
    }
    return true;
}

void find_Minimum_Answer(vector<int>& seq, int idx) {
    if (idx == n) {
        ans = seq;
        return;
    }

    for (int i = 0; i < 3; i++) {
        seq.push_back(value[i]);
        if (isValid(seq) && (ans.empty() || seq < ans))
            find_Minimum_Answer(seq, idx + 1);
        seq.pop_back();
    }
}

void solve() {
    vector<int> sequence;
    find_Minimum_Answer(sequence, 0);

    for (int i = 0; i < n; i++)
        cout << ans[i];
}

int main() {
    cin >> n;
    solve();
    return 0;
}