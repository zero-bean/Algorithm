#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& str, char delimeter) {
    vector<string> tokens;
    string token;
    stringstream ss(str.substr(1, str.size() - 2));

    while (getline(ss, token, delimeter))
        tokens.push_back(token);

    return tokens;
}

deque<int> conversion(string str) {
    vector<string> tokens = split(str, ',');
    deque<int> tmp;

    for (const string& token : tokens)
        tmp.push_back(stoi(token));

    return tmp;
}

void print_Result(deque<int>& q, const bool b, const bool dir) {
    if (!b) {
        cout << "error" << "\n";
        return;
    }

    cout << "[";
    while (!q.empty()) {
        if (dir) {
            cout << q.front();

            if (q.size() != 1)
                cout << ",";

            q.pop_front();
        }
        else {
            cout << q.back();

            if (q.size() != 1)
                cout << ",";

            q.pop_back();
        }
    }
    cout << "]" << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        string command[2];
        deque<int> dq;
        bool dir = true, check = true;
        int trial;

        cin >> command[0];
        cin >> trial;
        cin >> command[1];

        dq = conversion(command[1]);

        for (const char& cmd : command[0]) {
            if (cmd == 'R') {
                dir = !dir;
            }
            else if (cmd == 'D') {
                if (dq.empty()) {
                    check = false;
                    break;
                }

                dir ? dq.pop_front() : dq.pop_back();
            }
        }

        print_Result(dq, check, dir);
    }

    return 0;
}