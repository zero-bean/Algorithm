#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> AB, CD;
    
    // A와 B의 모든 합을 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
        }
    }
    
    // C와 D의 모든 합을 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            CD.push_back(C[i] + D[j]);
        }
    }

    // AB와 CD를 정렬
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long cnt = 0;

    // AB의 각 값에 대해 -CD에서 값이 몇 개 있는지 찾음
    for (int i = 0; i < AB.size(); i++) {
        int target = -AB[i];
        cnt += upper_bound(CD.begin(), CD.end(), target) - lower_bound(CD.begin(), CD.end(), target);
    }

    cout << cnt << endl;
    
    return 0;
}
