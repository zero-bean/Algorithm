#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> prefix;
int n, t;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> t;

    prefix.resize(n + 1, vector<int>(n + 1, 0));
    grid.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = grid[i][j] 
                + prefix[i - 1][j] 
                + prefix[i][j - 1]
                - prefix[i - 1][j - 1];
        }
    }

    while (t--) {
        int x[2], y[2];

        cin >> x[0] >> y[0];
        cin >> x[1] >> y[1];
        
        int tot = prefix[x[1]][y[1]] 
            - prefix[x[0] - 1][y[1]] 
            - prefix[x[1]][y[0] - 1] 
            + prefix[x[0] - 1][y[0] - 1];

        cout << tot << "\n";
    }

    return 0;
}