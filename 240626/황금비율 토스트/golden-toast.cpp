#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    int n, m;

    cin >> n >> m >> str;
    
    vector<char> bread(str.begin(), str.end());
    vector<char>::iterator it = bread.end();

    while (m--) {
        char c;
        cin >> c;

        if (c == 'L') {
            if (it != bread.begin())
                it--;
        }
        else if (c == 'R') {
            if (it != bread.end())
                it++;
        } 
        else if (c == 'D') {
            if (it != bread.end())
                it = bread.erase(it);
        }
        else if (c == 'P') {
            char cc;
            cin >> cc;
            it = bread.insert(it, cc);
            it++;
        }
    }

    for (const char& c : bread)
        cout << c;

    return 0;
}