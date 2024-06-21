#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (n % 2 == 0) {
                if (i % 2 == 0)
                    arr[j][i] = ((n - i - 1) * n) + (j + 1);
                 else
                    arr[j][i] = ((n - i) * n) - j;
            } 
            else {
                if (i % 2 == 0)
                    arr[j][i] = ((n - i) * n) - j;
                 else
                    arr[j][i] = ((n - i - 1) * n) + (j + 1);
            }
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}