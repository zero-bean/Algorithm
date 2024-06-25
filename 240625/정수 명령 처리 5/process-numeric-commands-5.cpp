#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class vec {
private:
    int size;
    int* arr = new int[10000];
public:
    vec() : size(0) {}

    ~vec() {
        delete[] arr;
    }

    void push_back(int n) {
        arr[size] = n;
        size++;
    }

    void pop_back() {
        arr[size-1] = NULL;
        size--;
    }

    int get(int n) { return arr[n - 1]; }

    int getSize() { return size; }
};

int main() {
    vec v;
    int n;

    cin >> n;
    cin.ignore();

    while (n--) {
        string line;

        getline(cin, line);

        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "push_back") {
            int num;
            ss >> num;
            v.push_back(num);
        }
        else if (command == "pop_back") {
            v.pop_back();
        }
        else if (command == "size") {
            cout << v.getSize() << endl;
        }
        else if (command == "get") {
            int num;
            ss >> num;
            cout << v.get(num) << endl;
        }
    }

    return 0;
}