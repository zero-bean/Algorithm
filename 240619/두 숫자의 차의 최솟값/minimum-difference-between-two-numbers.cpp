#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, min = 100;

    cin >> n;

    vector<int> vec(n);

    for (int i=0; i<vec.size(); i++) {
        cin >> vec[i];
    }

    for (int i=0; i<vec.size()-1; i++) {
        if (min > abs(vec[i] - vec[i+1]))
            min = abs(vec[i] - vec[i+1]);
    }

    cout << min;

    return 0;
}