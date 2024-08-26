#include <iostream>
#include <queue>
#include <limits>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

ll A, B;

void bfs() {
    map<ll, ll> trials;
    queue<ll> q;

    trials[A] = 0;
    q.push(A);

    while (!q.empty()) {
        ll curr = q.front();
        ll nxt[2] = { curr * 2, curr * 10 + 1 };
        q.pop();

        if (curr == B) {
            cout << trials[B] + 1 << endl;
            return;
        }

        for (int i = 0; i < 2; i++) {
            if (nxt[i] > B)
                continue;

            if (trials.find(nxt[i]) == trials.end() 
                || trials[nxt[i]] > trials[curr] + 1) {
                trials[nxt[i]] = trials[curr] + 1;
                q.push(nxt[i]);
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin >> A >> B;

    bfs();

    return 0;
}