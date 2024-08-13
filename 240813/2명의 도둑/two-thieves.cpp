#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> room;
vector<vector<pair<int, int>>> ways;
int n, m, c;

void generate_Combination(vector<pair<int, int>>& tmp, int row, int idx, int tot) {
    if (idx >= n || row >= n || tot > c)
        return;

    if (!tmp.empty())
        ways.push_back(tmp);

    if (tmp.size() == m)
        return;

    //generate_Combination(tmp, row + 1, idx, tot);
    tmp.push_back({ row, idx });
    generate_Combination(tmp, row, idx + 1, tot + room[row][idx]);
    tmp.pop_back();
    generate_Combination(tmp, row, idx + 1, tot);
}

bool check_Area(const vector<pair<int, int>>& e1, const vector<pair<int, int>>& e2) {
    if (e1[0].first != e2[0].first)
        return true;

    for (int i = 0; i < e1.size(); i++) {
        for (int j = 0; j < e2.size(); j++) {
            if (e1[i].second == e2[j].second)
                return false;
        }
    }

    return true;
}

void solve() {
    vector<pair<int, int>> element[2];
    vector<pair<int, int>> tmp;
    int answer = 0;

    for (int i=0; i<n; i++)
        generate_Combination(tmp, i, 0, 0);

    for (int i = 0; i < ways.size(); i++) {
        element[0] = ways[i];

        for (int j = i + 1; j < ways.size(); j++) {
            element[1] = ways[j];

            if (check_Area(element[0], element[1])) {
                int tot[2] = { 0, };

                for (int i = 0; i < 2; i++) {
                    for (const pair<int, int>& p : element[i])
                        tot[i] += (room[p.first][p.second] * room[p.first][p.second]);
                }

                answer = max(answer, tot[0] + tot[1]);
            }
        }
    }

    cout << answer << endl;
}

int main() {
    cin >> n >> m >> c;

    room.resize(n, vector<int>(n));

    for (vector<int>& r : room)
        for (int& i : r)
            cin >> i;

    solve();

    return 0;
}