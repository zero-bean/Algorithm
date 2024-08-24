#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> v;
vector<bool> visited;
int n, m;

void solve(int idx) {
    if (idx == m) { 
        for (const int& i : v)
            cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            visited[i] = true; 
            v.push_back(arr[i]);
            solve(idx + 1); 
            v.pop_back(); 
            visited[i] = false; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    arr.resize(n);
    visited.resize(n, false);

    for (int& i : arr)
        cin >> i;

    sort(arr.begin(), arr.end());

    solve(0);

    return 0;
}