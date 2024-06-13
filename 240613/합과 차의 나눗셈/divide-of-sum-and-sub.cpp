#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	int num1 = a + b;
	int num2 = a - b;
	double result = (double)num1 / (double)num2;
	cout << fixed;
	cout.precision(2);
	cout << result;

	return 0;
}