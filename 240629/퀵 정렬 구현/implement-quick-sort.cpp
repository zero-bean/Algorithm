#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void swap_data(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
int partition(vector<T>& v, int left, int right) {
	T pivot = v[left];
	int change_Position = left - 1;

	for (int i = left; i <= right; i++) {
		if (v[i] < pivot) {
			change_Position++;
			swap_data(v[i], v[change_Position]);
		}
	}

	swap_data(pivot, v[change_Position + 1]);

	return change_Position + 1;
}

template <typename T>
void quick_Sort(vector<T>& v, int left, int right) {
	if (left < right) {
		int position = partition(v, left, right);

		quick_Sort(v, left, position - 1);
		quick_Sort(v, position + 1, right);
	}
}

template <typename T>
void print_Result(const vector<T>& v) {
	for (T t : v)
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