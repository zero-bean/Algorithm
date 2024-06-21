#include <iostream>
#include <vector>

using namespace std;

void initializeVector(vector<vector<int>>& v, const vector<vector<int>>& p) {
    for (int i=0; i<v.size(); i++)
        v[i].assign(v[i].size(), 0);

    for (int i=0; i<p.size(); i++) {
        int x = p[i][0];
        int y = p[i][1];
        v[x-1][y-1] = x * y;
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
    int n, m;
    
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(n));
    vector<vector<int>> points(m, vector<int>(2));

    for (int i=0; i<points.size(); i++)
        cin >> points[i][0] >> points[i][1];

    initializeVector(vec, points);

    printVector(vec);

    return 0;
}