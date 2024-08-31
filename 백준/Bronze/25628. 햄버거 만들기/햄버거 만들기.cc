#include <iostream>

using namespace std;

int main() {
    int a, b, cnt = 0;
    
    cin >> a >> b;
    
    while (a >= 2 && b >= 1) {
        cnt++;
        a-=2;
        b-=1;
    }
    
    cout << cnt << endl;
    
    return 0;
}