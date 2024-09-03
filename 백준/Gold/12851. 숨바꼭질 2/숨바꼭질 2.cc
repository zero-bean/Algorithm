#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int shortests[100001];
int ways[100001] = { 0, };

void BFS(int start, int end) {
    queue<int> q;
    q.push(start);
    shortests[start] = 0;
    ways[start] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int nxt[3] = { curr - 1, curr + 1, curr * 2 };

        for (int i = 0; i < 3; i++) {
            if (nxt[i] < 0 || nxt[i] > 100000) 
                continue;

            if (shortests[nxt[i]] == -1) {
                shortests[nxt[i]] = shortests[curr] + 1;
                ways[nxt[i]] = ways[curr];
                q.push(nxt[i]);
            }
            else if (shortests[nxt[i]] == shortests[curr] + 1) {
                ways[nxt[i]] += ways[curr];
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	fill(shortests, shortests + 100001, -1);

	BFS(N, K);

	cout << shortests[K] << endl;
	cout << ways[K] << endl;

	return 0;
}