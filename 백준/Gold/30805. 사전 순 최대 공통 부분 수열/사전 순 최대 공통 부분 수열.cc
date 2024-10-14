#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct vu {
    int value;
    int idx;

    vu(int v, int i) : value(v), idx(i) {};
};

struct vt {
    int value;
    int a_idx;
    int b_idx;

    vt(int v, int i1, int i2) : value(v), a_idx(i1), b_idx(i2) {};
};

bool Cmp_Intt(const vu& i1, const vu& i2) {
    if (i1.value == i2.value)
        return i1.idx < i2.idx;

    return i1.value > i2.value;
}

int n, m;
vector<vu> A, B;
vector<vt> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 0, j = 0;
    int input;

    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> input;
        A.push_back(vu(input, idx));
    }

    cin >> m;
    for (int idx = 0; idx < m; idx++) {
        cin >> input;
        B.push_back(vu(input, idx));
    }

    sort(A.begin(), A.end(), Cmp_Intt);
    sort(B.begin(), B.end(), Cmp_Intt);

    while (i < n && j < m) {
        if (A[i].value > B[j].value)
            i++;
        else if (A[i].value < B[j].value)
            j++;
        else {
            if (arr.empty()) {
                arr.push_back(vt(A[i].value, A[i].idx, B[j].idx));
                i++;
                j++;
            }
            else if (A[i].idx < arr.back().a_idx)
                i++;
            else if (B[j].idx < arr.back().b_idx)
                j++;
            else {
                arr.push_back(vt(A[i].value, A[i].idx, B[j].idx));
                i++;
                j++;
            }
        }
    }

    cout << arr.size() << endl;
    for (const auto& a : arr)
        cout << a.value << " ";
    cout << endl;

    return 0;
}