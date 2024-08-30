#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0;
    int right = n - 1;
    int min_gap = INT_MAX;
    pair<int, int> ans;

    while (left < right) {
        int sum = arr[left] + arr[right];
        int gap = abs(sum);

        if (gap < min_gap) {
            min_gap = gap;
            ans = { arr[left], arr[right] };
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << ans.first << " " << ans.second << endl;
    return 0;
}
