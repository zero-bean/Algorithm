#include <iostream>
#include <vector>

using namespace std;

void swap_data(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void heapify(vector<int>& v, int parent, int n) {
	int largest = parent;
	int left = parent * 2 + 1;
	int right = left + 1;

	if (left < n && v[left] > v[largest])
		largest = left;

	if (right < n && v[right] > v[largest])
		largest = right;

	if (largest != parent) {
		swap_data(v[largest], v[parent]);
		heapify(v, largest, n);
	}
}

void heap_Sort(vector<int>& v) {
	int size = v.size();

	for (int parent = size / 2; parent >= 0; parent--)
		heapify(v, parent, size);

	for (int parent = size - 1; parent > 0; parent--) {
		swap_data(v[0], v[parent]);
		heapify(v, 0, parent - 1);
	}

}

void print_Result(const vector<int>& v) {
	for (int t : v)
		cout << t << " ";
	cout << endl;
}

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);

	for (int& num : vec)
		cin >> num;

	heap_Sort(vec);

	print_Result(vec);

	return 0;
}