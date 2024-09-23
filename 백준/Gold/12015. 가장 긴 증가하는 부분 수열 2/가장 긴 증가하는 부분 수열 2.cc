#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int n;

int Binary_Search_LB(vector<int>& d, int target) {
    int left = 0;
    int right = d.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (d[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}

void Solve() {
    vector<int> DP;

    DP.push_back(vec[0]);

    for (int i = 1; i < n; i++) {
        if (DP[DP.size() - 1] < vec[i])
            DP.push_back(vec[i]);
        else {
            int border = Binary_Search_LB(DP, vec[i]);
            DP[border] = vec[i];
        }
    }

    cout << DP.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vec.assign(n, 0);

    for (int& i : vec)
        cin >> i;

    Solve();

    return 0;
}