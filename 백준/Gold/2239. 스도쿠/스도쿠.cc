#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> grid(9, vector<int>(9));
vector<pair<int, int>> spaces;

bool can_Write(pair<int,int> p, int value) {
    int x = p.first;
    int y = p.second;
    int areaX = x / 3 * 3;
    int areaY = y / 3 * 3;

    for (int i = 0; i < 9; i++) {
        if (grid[x][i] == value || grid[i][y] == value)
            return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[areaX + i][areaY + j] == value)
                return false;
        }
    }

    return true;
}

bool backTracking(int idx) {
    if (idx == spaces.size())
        return true; 

    pair<int, int> p = spaces[idx];

    for (int num = 1; num <= 9; num++) {
        if (can_Write(p, num)) {
            grid[p.first][p.second] = num;
            if (backTracking(idx + 1))
                return true; 
            grid[p.first][p.second] = 0;
        }
    }

    return false;
}

void print_Result() {
    for (const vector<int>& g : grid) {
        for (const int& i : g)
            cout << i;
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 9; i++) {
        string str;

        cin >> str;

        for (int j = 0; j < 9; j++) {
            int num = str[j] - '0';
            
            grid[i][j] = num;

            if (grid[i][j] == 0)
                spaces.emplace_back(i, j);
        }
    }

    backTracking(0);

    print_Result();

    return 0;
}