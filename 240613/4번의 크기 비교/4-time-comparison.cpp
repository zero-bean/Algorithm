#include <iostream>
#include <array>

using namespace std;

int main() {
	
	array<int, 5> arr;
	
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}

	for (int i = 1;  i < arr.size(); i++) {
		if (arr[0] > arr[i])
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}