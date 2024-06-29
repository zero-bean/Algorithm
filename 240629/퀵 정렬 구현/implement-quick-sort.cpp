#include <iostream>
#include <vector>

using namespace std;

void swap_data(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(vector<int>& v, int left, int right) {
	int pivot = v[right];
	int change_Position = left;

	for (int i = left; i < right; i++) {
		if (v[i] < pivot) {
			swap_data(v[i], v[change_Position]);
			change_Position++;
		}
	}

	swap_data(v[change_Position], v[right]);
	return change_Position;
}

void quick_Sort(vector<int>& v, int left, int right) {
	if (left < right) {
		int position = partition(v, left, right);
		quick_Sort(v, left, position - 1);
		quick_Sort(v, position + 1, right);
	}
}

void print_Result(const vector<int>& v) {
	for (int t : v)
		cout << t << " ";
}

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);

	for (int& num : vec)
		cin >> num;

	quick_Sort(vec, 0, n - 1);

	print_Result(vec);

	return 0;
}