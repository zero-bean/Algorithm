#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> weights = {};
int N = 0;

void Solve() {
    int sum = 0;
    
    sort(weights.begin(), weights.end(), less<int>());

    for (const auto& weight : weights) {
        if (weight > sum + 1)
            break;

        sum += weight;
    }

    cout << sum + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    weights.resize(N);
    for (auto& origin : weights)
        cin >> origin;

    Solve();

    return 0;
}