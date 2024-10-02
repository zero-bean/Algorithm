#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A, B;
int T, N, M;

int B_upper_Bound(const vector<int>& v, int value) {
    int left = 0;
    int right = v.size();

    while (left < right) {
        int mid = (left + right) / 2;

        if (v[mid] <= value)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

int B_lower_Bound(const vector<int>& v, int value) {
    int left = 0;
    int right = v.size();

    while (left < right) {
        int mid = (left + right) / 2;

        if (v[mid] >= value)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}

vector<int> prefix_Sum(const vector<int>& origin, const int sz) {
    vector<int> prefix(sz + 1, 0);
    vector<int> tmp;

    for (int i = 1; i <= sz; i++)
        prefix[i] = origin[i] + prefix[i - 1];

    for (int i = 1; i <= sz; i++) {
        for (int j = 0; j < i; j++)
            tmp.push_back(prefix[i] - prefix[j]);
    }

    return tmp;
}

void solve() {
    vector<int> As = prefix_Sum(A, N);
    vector<int> Bs = prefix_Sum(B, M);
    unsigned long long cnt = 0;
    
    sort(Bs.begin(), Bs.end(), less<int>());

    for (int i = 0; i < As.size(); i++) {
        int upper = B_upper_Bound(Bs, T - As[i]);
        int lower = B_lower_Bound(Bs, T - As[i]);
        cnt += upper - lower;
    }

    cout << cnt << endl;
}

void get_Input() {
    cin >> T >> N;

    A.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> M;

    B.assign(M + 1, 0);
    for (int i = 1; i <= M; i++)
        cin >> B[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    get_Input();

    solve();

    return 0;
}