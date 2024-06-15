#include <iostream>

using namespace std;

int main() {
    int n, count = 0;

    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i % 2 == 0)
                count+=2;
            else
                count+=1;

            cout << count << " ";
        }
        cout << endl;
    }

    return 0;
}