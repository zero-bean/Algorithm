#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tot = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (pq.size() > 1) {
        int c1, c2, c3;
        c1 = pq.top();
        pq.pop();
        c2 = pq.top();
        pq.pop();

        c3 = c1 + c2;
        tot += c3;
        pq.push(c3);
    }

    cout << tot << endl;

    return 0;
}