#include <iostream>

using namespace std;

int main() {
	
	int a, b, sum = 1;

	cin >> a >> b;


	for (int i = 1; i <= b; i++) {
		if (i % a == 0)
			sum *= i;
	}

	cout << sum;

	return 0;
}