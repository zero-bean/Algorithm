#include <iostream>
#include <array>

using namespace std;

int main() {
	
	array<int, 5> arr;
	int count = 0;


	for (int i = 0; i < arr.size(); i++)
		cin >> arr[i];
	
	for (int num : arr) {
		if (num % 2 == 0)
			count++;
	}

	cout << count;

	return 0;
}