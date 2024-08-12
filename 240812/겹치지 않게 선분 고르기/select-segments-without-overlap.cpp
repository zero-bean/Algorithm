#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

void select(const vector<pair<int, int>>& lines, vector<pair<int, int>>& tmp, int idx) {
    if (idx >= lines.size())
        return;
    
    pair<int, int> last = tmp[tmp.size() - 1];

    if (last.second < lines[idx].first)
        tmp.push_back(lines[idx]);

    select(lines, tmp, idx + 1);
}

void solve(const vector<pair<int, int>>& lines, vector<pair<int, int>>& ans) {
    for (int i = 0; i < lines.size() - 1; i++) {
        vector<pair<int, int>> tmp;
        tmp.push_back(lines[i]);
        select(lines, tmp, i + 1);

        ans = ans.size() < tmp.size() ? tmp : ans;
    }
}

int main() {
    vector<pair<int, int>> answer;
    int n;

    cin >> n;

    vector<pair<int, int>> lines(n);

    for (pair<int, int>& line : lines)
        cin >> line.first >> line.second;

    sort(lines.begin(), lines.end(), comp);

    solve(lines, answer);

    cout << answer.size();

    return 0;
}