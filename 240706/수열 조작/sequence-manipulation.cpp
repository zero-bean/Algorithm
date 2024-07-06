#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> q;
    int n;

    cin >> n;

    for (int i=1; i<=n; i++)
        q.push_back(i);

    while (q.size() != 1) {
        q.pop_front();
        q.push_back(q.front());
        q.pop_front();
    }

    cout << q.front();

    return 0;
}