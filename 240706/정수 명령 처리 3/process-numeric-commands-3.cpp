#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    deque<int> q;
    int n;

    cin >> n;

    while (n--) {
        string str;

        cin >> str;
    
        if (str == "push_front") {
            int num;

            cin >> num;

            q.push_front(num);
        }
        else if (str == "push_back") {
            int num;

            cin >> num;

            q.push_back(num);
        }
        else if (str == "pop_front") {
            cout << q.front() << endl;
            q.pop_front();
        }
        else if (str == "pop_back") {
            cout << q.back() << endl;
            q.pop_back();
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
        else if (str == "back") {
            cout << q.back() << endl;
        }
    }

    return 0;
}