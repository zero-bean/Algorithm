#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 10> arr;

    cin >> arr[0] >> arr[1];

    for (int i=2; i<arr.size(); i++) {
        arr[i] = arr[i-1] + 2 * arr[i-2];
    }

    for (int num : arr)
        cout << num << " ";

    return 0;
}