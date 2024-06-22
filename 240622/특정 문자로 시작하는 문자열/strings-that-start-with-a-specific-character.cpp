#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, count = 0;
    float avg = 0;
    char c;

    cin >> n;
    cin.ignore();

    vector<string> vec(n);
    for (string& s : vec)
        getline(cin, s);

    cin.get(c);

    for (string& s : vec) {
        if (s[0] == c) {
            avg += s.length();
            count++;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << count << " " << avg / count;

    return 0;
}