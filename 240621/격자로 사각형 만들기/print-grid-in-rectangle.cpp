#include <iostream>
#include <vector>

using namespace std;

void initializeVector(vector<vector<int>>& v) {
    for (int i=0; i<v[0].size(); i++)
        v[0][i] = 1;
    
    for (int i=0; i<v.size(); i++)
        v[i][0] = 1;

    for (int i=1; i<v.size(); i++) {
        for (int j=1; j<v[i].size(); j++)
            v[i][j] = v[i-1][j] + v[i][j-1] + v[i-1][j-1];
    }
}

void printVector(const vector<vector<int>>& v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n;
    
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));

    initializeVector(vec);

    printVector(vec);

    return 0;
}