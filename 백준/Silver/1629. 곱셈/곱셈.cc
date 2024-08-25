#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll solve_By_Recursion(ll base, ll exponent, ll mod) {
    if (exponent == 0)
        return 1;

    ll half = solve_By_Recursion(base, exponent / 2, mod);

    if (exponent % 2 == 0)
        return (half * half) % mod;
    else
        return ((half * half) % mod) * base % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;

    cout << solve_By_Recursion(A, B, C) << endl;

    return 0;
}