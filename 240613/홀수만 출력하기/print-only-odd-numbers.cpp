#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;

	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < vec.size(); i++)
		cin >> vec[i];
	
	for (int num : vec) {
		if (num % 3 == 0 && num % 2 != 0)
			cout << num << endl;
	}

	return 0;
}