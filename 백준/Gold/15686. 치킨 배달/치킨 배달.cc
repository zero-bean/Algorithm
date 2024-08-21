#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

vector<vector<int>> city;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int n, m;
int answer = numeric_limits<int>::max();

void generate_Combination(vector<vector<int>>& s, vector<int>& t, int idx) {
    if (t.size() == m) {
        s.push_back(t);
        return;
    }

    if (idx >= chicken.size())
        return;

    t.push_back(idx);
    generate_Combination(s, t, idx + 1);
    t.pop_back();
    generate_Combination(s, t, idx + 1);
}

void solve() {
    vector<int> chicken_Dists(house.size(), numeric_limits<int>::max());
    vector<vector<int>> combinations;
    vector<int> tmp;

    generate_Combination(combinations, tmp, 0);

    for (const vector<int>& combination : combinations) {
        fill(chicken_Dists.begin(), chicken_Dists.end(), numeric_limits<int>::max());
        int tot = 0;

        for (const int& element : combination) {
            pair<int, int> store_pos = chicken[element];
            
            for (int i = 0; i < house.size(); i++) {
                int dist = abs(house[i].first - store_pos.first) + abs(house[i].second - store_pos.second);
                chicken_Dists[i] = min(chicken_Dists[i], dist);
            }
        }

        for (const int& chicken_dist : chicken_Dists)
            tot += chicken_dist;

        answer = min(answer, tot);
    }

    cout << answer << endl;
}

int main() {
    cin >> n >> m;

    city.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];

            if (city[i][j] == 2)
                chicken.push_back({ i, j });

            if (city[i][j] == 1)
                house.push_back({ i, j });
        }
    }

    solve();

    return 0;
}