#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> b >> a;

	int num = b;
	while (num >= a) {
		cout << num << " ";

		num-=2;
	}
	
	return 0;
}