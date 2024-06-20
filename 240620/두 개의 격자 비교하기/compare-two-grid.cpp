#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[i].size(); j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[i].size(); j++) {
            int num;
            cin >> num;

            if (num != arr[i][j])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }


    return 0;
}