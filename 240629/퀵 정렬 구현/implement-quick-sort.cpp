#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
T select_Pivot(vector<T>& v, int left, int right) {
	int size = right - left;
	if (size >= 3) {
		T data[3] = { v[left], v[(left + right) / 2], v[right] };
		int smallest = min(data[0], min(data[1], data[2]));
		int largest = max(data[0], max(data[1], data[2]));
		int middle = data[0] + data[1] + data[2] - smallest - largest;
		return middle;
	}
	else {
		return v[left];
	}
}

template <typename T>
void swap_data(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
int partition(vector<T>& v, int left, int right) {
	T pivot = select_Pivot(v, left, right);
	int i = left;
	int j = right;

	while (i < j) {
		while (v[j] > pivot && j >= left)
			j--;

		while (v[i] < pivot && i <= right)
			i++;

		if (i < j)
			swap_data(v[i], v[j]);
		else
			swap_data(pivot, v[i]);
	}

	return i;
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