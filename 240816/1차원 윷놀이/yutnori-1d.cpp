#include <iostream>
#include <vector>

using namespace std;

int m, k, n;
int score = 0;
vector<int> dist;
vector<int> rush;

int calculate_Score() {
    int tmp = 0;

    for (const int& d : dist) {
        if (d >= m)
            tmp++;
    }

    return tmp;
}

void generate_Combination(int idx) {
    if (idx >= n) {
        score = max(score, calculate_Score());
        return;
    }


    for (int i = 0; i < k; i++) {
        if (dist[i] < m) {
            dist[i] += rush[idx];
            generate_Combination(idx + 1);
            dist[i] -= rush[idx];
        }
    }
}

void solve() {
    generate_Combination(0);

    cout << score << endl;
}

int main() {
    cin >> n >> m >> k;

    rush.resize(n);
    for (int& i : rush)
        cin >> i;

    dist.resize(k, 1);

    solve();

    return 0;
}