#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        q.push(i);

    while (!q.empty()) {
        for (int j = 1; j < k; j++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}