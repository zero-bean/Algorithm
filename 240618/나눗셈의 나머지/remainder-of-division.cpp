#include <iostream>
#include <array>

using namespace std;

int main() {
    int a, b, total = 0;
    array<int, 10> arr;
    arr.fill(0);

    cin >> a >> b;

    while (a > 1) {
        arr[a%b]++;
        a /= b;
    }

    for (int num: arr) {
        if (num == 0)
         continue;

         total += (num*num);
    }

    cout << total;

    return 0;
}