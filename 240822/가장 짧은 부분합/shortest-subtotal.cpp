#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    int n, s, sum = 0;
    int j = 0;
    int ans = numeric_limits<int>::max();

    cin >> n >> s;

    vec.resize(n);
    for (int& i : vec)
        cin >> i;

    for (int i = 0; i < n; i++) {
        while (j < n && sum < s) {
            sum += vec[j];
            j++;
        }
        
        if (sum >= s)
            ans = min(ans, j - i);

        sum -= vec[i];
    }

    if (ans == numeric_limits<int>::max())
        cout << -1;
    else
        cout << ans;

    return 0;
}