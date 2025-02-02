#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> budgets;
int N, budgetLimit;

void Solve() {
    int answer = 0;
    int left = 0;
    int right = budgets.back();
    int mid;

    while (left <= right) {
        long long usedBudget = 0;
        mid = static_cast<int>((left + right) / 2);

        for (const auto& budget : budgets) {
            usedBudget += min(mid, budget);
        }

        if (usedBudget > budgetLimit) {
            right = mid - 1;
        }
        else {
            answer = mid;
            left = mid + 1;
        }
    }

    cout << answer << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    budgets = vector<int>(N);
    for (auto& budget : budgets)
        cin >> budget;
    cin >> budgetLimit;

    sort(budgets.begin(), budgets.end());

    Solve();

    return 0;
}