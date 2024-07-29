#include <iostream>
#include <vector>
using namespace std;

void brute_Force(const vector<vector<int>>& t) {
    int max = 0;

    for (int i = 0; i <= t.size() - 3; i++) {
        for (int j = 0; j <= t.size() - 3; j++) {
            int tmp = 0;
            for (int k = i; k <= i + 2; k++) {
                for (int u = j; u <= i+2; u++) {
                    if (t[k][u] == 1)
                        tmp++;
                }
            }
            max = max < tmp ? tmp : max;
        }
    }

    cout << max << endl;
} 

int main() {
    int N;
    cin >> N;

    vector<vector<int>> table(N, vector<int>(N, 0));
    for (vector<int>& v : table) {
        for (int& n : v)
            cin >> n;
    }

    brute_Force(table);

    return 0;
}