#include <iostream>
#include <vector>

using namespace std;

void counting(const  vector<vector<int>>& v, int m) {
    if (m == 1) {
        cout << v.size() * 2;
        return;

    }

    int size = v.size();
    int answer = 0;

    for (int i = 0; i < size; i++) {
        int count = 1;

        for (int j = 1; j < size; j++) {
            if (v[i][j] == v[i][j-1]) {
                count++;

                if (count >= m) {
                    answer++;
                    break;
                }
            }
            else {
                count = 1;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        int count = 1;

        for (int j = 1; j < size; j++) {
            if (v[j][i] == v[j-1][i]) {
                count++;

                if (count >= m) {
                    answer++;
                    break;
                }
            }
            else {
                count = 1;
            }


        }
    }

    cout << answer;
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(n));

    for (vector<int>& v : vec) {
        for (int& i : v)
            cin >> i;
    }

    counting(vec, m);

    return 0;
}