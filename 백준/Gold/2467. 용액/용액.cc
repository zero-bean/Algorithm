#include <iostream>
#include <vector>

using namespace std;

pair<int, int> p;
vector<int> arr;
int n, ans = 2'000'000'000;

void binary_Search() {
    int left = 0; 
    int right = n - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        int sum = arr[left] + arr[right];

        if (ans >= abs(sum)) {
            ans = abs(sum);
            p = { arr[left], arr[right] };
        }

        if (sum < 0)
            left++;
        else
            right--;
    }
}

void solve() {
    binary_Search();

    cout << p.first << " " << p.second << "\n";
}

int main() {
    cin >> n;

    arr.resize(n);
    for (int& i : arr)
        cin >> i;

    solve();

    return 0;
}