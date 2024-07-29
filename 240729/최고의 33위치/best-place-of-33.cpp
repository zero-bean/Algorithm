#include <iostream>
#include <vector>
using namespace std;

void brute_Force(const vector<vector<int>>& t) {
    int max = 0;

    for (int i = 0; i <= t.size() - 3; i++) {
        int tmp = 0;

        for (int j = i; j < i + 3; j++) {
            for (int k = i; k < i + 3; k++) {
                if (t[j][k] == 1)
                    tmp++;
            }
        }

        max = (max > tmp ? max : tmp);
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