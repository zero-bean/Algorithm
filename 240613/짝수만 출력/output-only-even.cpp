#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	int num = a;
	while (true) {
		if (num > b)
			break;

		if (num % 2 == 0)
			cout << num << " ";

		num++;
	}
	
	return 0;
}