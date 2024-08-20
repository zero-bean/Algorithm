#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> grid(3);
vector<int> dp_min(3);
vector<int> dp_max(3);
int n;

void solve() {
    vector<int> copy_max = dp_max;
    vector<int> copy_min = dp_min;

    dp_max[0] = max(copy_max[0], copy_max[1]) + grid[0];
    dp_max[1] = max(copy_max[0], max(copy_max[1], copy_max[2])) + grid[1];
    dp_max[2] = max(copy_max[1], copy_max[2]) + grid[2];

    dp_min[0] = min(copy_min[0], copy_min[1]) + grid[0];
    dp_min[1] = min(copy_min[0], min(copy_min[1], copy_min[2])) + grid[1];
    dp_min[2] = min(copy_min[1], copy_min[2]) + grid[2];
}

int main() {
    cin >> n;

    for (int i = 0; i < 3; i++)
        cin >> grid[i];

    for (int i = 0; i < 3; i++)
        dp_max[i] = dp_min[i] = grid[i];

    for (int i = 1; i < n; i++) {
        for (int& g : grid)
            cin >> g;

        solve();
    }

    cout << max(dp_max[0], max(dp_max[1], dp_max[2])) << " ";
    cout << min(dp_min[0], min(dp_min[1], dp_min[2])) << endl;

    return 0;
}