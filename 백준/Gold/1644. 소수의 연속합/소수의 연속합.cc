#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;
int n;

void find_Primes() {
    vector<bool> visited(n + 1, true);

    visited[0] = visited[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (visited[i]) {
            for (int j = i * i; j <= n; j+=i)
                visited[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (visited[i])
            primes.push_back(i);
    }
}

int find_Cnt() {
    int cnt = 0;
    int sum = 0;
    int j = primes.size() - 1;

    for (int i = primes.size() - 1; i >= 0; i--) {

        while (j >= 0 && sum < n) {
            sum += primes[j];
            j--;

            if (sum == n)
                cnt++;
        }

        sum -= primes[i];
    }

    return cnt;
}

void solve() {
    find_Primes();

    cout << find_Cnt() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    solve();

    return 0;
}