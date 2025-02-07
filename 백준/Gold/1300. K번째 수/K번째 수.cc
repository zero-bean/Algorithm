#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, K = 0;

int Lower_Bound() {
    long long left = 1;
    long long right = static_cast<long long>(N) * N;
    long long mid = 0;
    long long cnt = 0;

    while (left < right) {
        mid = (left + right) / 2;

        cnt = 0;
        for (int i = 1; i <= N; i++)
            cnt += min(static_cast<int>(mid / i), N);

        if (K > cnt)
            left = mid + 1;
        else if (K <= cnt)
            right = mid;
    }

    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    cout << Lower_Bound() << endl;

    return 0;
}