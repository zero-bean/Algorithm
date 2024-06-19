#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> vec(4, vector<int>(4));
    int total = 0;

    for (int i=0; i<vec.size(); i++) {
        for (int j=0; j<vec[i].size(); j++) {
            cin >> vec[i][j];
        }
    }

    for (int i=0; i<vec.size(); i++) {
        for (int j=0; j<=i; j++)
            total += vec[i][j];
    }

    cout << total;

    return 0;
}