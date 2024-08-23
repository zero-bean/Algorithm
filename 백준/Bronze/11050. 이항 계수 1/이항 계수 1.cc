#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int n, k;

void solve(int idx, int& cnt) {
    if (vec.size() >= k) {
        cnt++;
        return;
    }
    
    if (idx > n)
        return;
    
    
    vec.push_back(idx);
    solve(idx + 1, cnt);
    vec.pop_back();
    solve(idx + 1, cnt);
}

int main() {
    int cnt = 0;
    
    cin >> n >> k;
    
    solve(1, cnt);
    
    cout << cnt << endl;
}