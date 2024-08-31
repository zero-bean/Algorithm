#include <iostream>

using namespace std;

int main() {
    int n;
    
    while (true) {
        cin >> n;
        
        if (n == 0)
            break;
        
        if (n % 2 == 0)
            cout << (1+n) * (n/2) << endl;
        else
            cout << n * (n/2 + 1) << endl;
    }
    
    return 0;
}