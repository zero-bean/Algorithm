#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 5> arr;

    for (int i=0; i<arr.size(); i++)
        cin >> arr[i];

    for (int num : arr) {
        if (num % 3 !=0) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;

    return 0;
}