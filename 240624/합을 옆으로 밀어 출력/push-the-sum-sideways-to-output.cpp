#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, total = 0;

    cin >> n;

    vector<int> vec(n);
    for (int& num : vec) {
        cin >> num;
        total += num;
    }

    string str = to_string(total);

    char c = str[0];
    str.erase(0, 1);
    str.push_back(c);

    cout << str;

    return 0;
}