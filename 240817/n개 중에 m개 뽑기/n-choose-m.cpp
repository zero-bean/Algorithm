#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> cnt;
int n, m;

bool is_Right() {
    for(const int& c : cnt) {
        if (c > 1)
            return false;
    }

    return true;
}

void solve(int idx) {
    if (idx >= m) {
            for (const int& num : nums)
                cout << num << " ";
            cout << endl;

        return;
    }

    for (int i=1; i<=n; i++) {
        if (nums.size() == 0 || (nums.size() >= 1 && nums[idx - 1] < i)) {
            nums.push_back(i);
            solve(idx + 1);
            nums.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;

    cnt.resize(m, 0);

    solve(0);

    return 0;
}