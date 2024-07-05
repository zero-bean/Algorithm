#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<char> s;
    string str;

    cin >> str;

    for (const char& c : str) {
        if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            if (!s.empty())
                s.pop();
        }
    }

    s.empty() ? cout << "Yes\n" : cout << "No\n";

    return 0;
}