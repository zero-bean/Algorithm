#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int n;

    cin >> n;

    while (n--) {
        string str;
        cin >> str;
    
        if (str == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (str == "pop") {
            cout << s.top() << endl;
            s.pop();
        }
        else if (str == "size") {
            cout << s.size() << endl;
        }
        else if (str == "empty") {
            cout << s.empty() << endl;
        }
        else if (str == "top") {
            cout << s.top() << endl;
        }
    }

    return 0;
}