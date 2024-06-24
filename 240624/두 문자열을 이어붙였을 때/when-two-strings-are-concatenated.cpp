#include <iostream>
#include <string>

using namespace std;

int main() {
    string str[2];
    
    for (string& s : str)
        getline(cin, s);

    str[0] + str[1] == str[1] + str[0] ? cout << "true" : cout << "false";

    return 0;
}