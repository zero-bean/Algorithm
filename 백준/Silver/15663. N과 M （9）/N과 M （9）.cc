#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<vector<int>> mySet;
vector<int> arr;
vector<bool> visited;
int N, M;

bool cmp_Array(const int& a, const int& b) { return a < b; }

void generate_Combinations(vector<int>& tmp, int idx) {
    if (tmp.size() == M) {
        if (mySet.find(tmp) == mySet.end()) {
            mySet.insert(tmp);

            for (const int& i : tmp)
                cout << i << " ";
            cout << endl;
        }

        return;
    }

    if (idx == N)
        return;

    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;

        tmp.push_back(arr[i]);
        visited[i] = true;
        generate_Combinations(tmp, i);
        visited[i] = false;
        tmp.pop_back();
    }
}

void solve() {
    vector<int> tmp;
    
    generate_Combinations(tmp, 0);
}

int main() {
    cin >> N >> M;

    arr.resize(N);
    visited.resize(N, false);

    for (int& i : arr)
        cin >> i;

    sort(arr.begin(), arr.end(), cmp_Array);
    
    solve();

    return 0;
}