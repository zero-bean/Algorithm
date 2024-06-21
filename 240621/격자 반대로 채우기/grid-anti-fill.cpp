#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i=0; i<arr.size(); i+=2) {
        for (int j=0; j<arr[i].size(); j++)
            arr[j][i] =  (n-i-1)*n + j +1 ;
    }

    for (int i=1; i<arr.size(); i+=2) {
        for (int j=0; j<arr[i].size(); j++)
            arr[j][i] =  (n-i)*n - j;
    }

    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}