#include <iostream>

using namespace std;

int main() {
	int a, n;

	cin >> a >> n;

	for (int i = 0; i < n; i++) {
		a += n;
		cout << a << endl;
	}
	
	return 0;
}