#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    int n, s;
    int ans = 10000000;

    cin >> n >> s;

    vec.resize(n);
    for(int& i : vec)
        cin >> i;

    for (int i=0; i<n; i++) {
        int tmp = 0;
        int cnt = 1;

        for (int j=i; j<n; j++) {
            if (tmp + vec[j] >= s) {
                ans = min(ans, cnt);
                break;
            }

            tmp += vec[j];
            cnt++;
        }
    }

    cout << ans;

    return 0;
}