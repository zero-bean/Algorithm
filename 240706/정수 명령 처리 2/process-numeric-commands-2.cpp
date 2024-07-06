#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int n;

    cin >> n;

    while (n--) {
        string str;

        cin >> str;
    
        if (str == "push") {
            int num;

            cin >> num;

            q.push(num);
        }
        else if (str == "pop") {
            cout << q.front() << endl;
            q.pop();
        }
        else if (str == "size") {
            cout << q.size() << endl;
        }
        else if (str == "empty") {
            cout << q.empty() << endl;
        }
        else if (str == "front") {
            cout << q.front() << endl;
        }
    }

    return 0;
}