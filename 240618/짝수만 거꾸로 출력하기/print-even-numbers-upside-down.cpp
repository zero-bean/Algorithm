#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int>vec(n);

    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    for (int i=n-1; i>=0; i--) {
        if (vec[i] % 2 == 0)
            cout << vec[i] << " ";
    }

    return 0;
}