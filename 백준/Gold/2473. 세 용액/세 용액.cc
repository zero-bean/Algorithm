#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(3);
vector<int> arr;
int n;
long long ans = 4'000'000'000;

void two_Pointer_Search(int idx) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (left == idx) {
            left++;
            continue;
        }
        else if (right == idx) {
            right--;
            continue;
        }

        long long sum = (long long)arr[left] + (long long)arr[right] + (long long)arr[idx];

        if (abs(ans) > abs(sum)) {
            ans = abs(sum);
            p = { arr[left], arr[right], arr[idx] };
        }

        if (sum < 0)
            left++;
        else
            right--;
    }
}

void solve() {
    p = { arr[0], arr[1], arr[2] };

    for (int i = 0; i < n; i++)
        two_Pointer_Search(i);

    sort(p.begin(), p.end(), less<int>());

    cout << p[0] << " " << p[1] << " " << p[2] << endl;
}

int main() {
    cin >> n;

    arr.resize(n);
    for (int& i : arr)
        cin >> i;

    sort(arr.begin(), arr.end(), less<int>());

    solve();

    return 0;
}