#include <iostream>
#include <vector>
#include <string>

using namespace std;

void countSubsequence(const vector<string>& v) {
    int count = 0;

    for (int i=0; i<v[0].size() - v[1].size(); i++) {
        if (v[0].substr(i, v[1].size()) == v[1])
            count++;
    }

    cout << count;
}

int main() {
    vector<string> vec(2);

    for (string& s : vec)
        getline(cin, s);

    countSubsequence(vec);

    return 0;
}