#include <iostream>
#include <vector>

using namespace std;

void swap_data(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void merge(vector<int>& v, vector<int>& tmp, int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			tmp[k] = v[i];
			i++;
		}
		else {
			tmp[k] = v[j];
			j++;
		}

		k++;
	}

	while (i <= mid) {
		tmp[k] = v[i];
		k++;
		i++;
	}

	while (j <= right) {
		tmp[k] = v[j];
		k++;
		j++;
	}

	for (int l = left; l <= right; l++)
		v[l] = tmp[l];
}

void merge_Sort(vector<int>& v, vector<int>& tmp, int left, int right) {
	int mid = (left + right) / 2;

	if (left < right) {
		merge_Sort(v, tmp, left, mid);
		merge_Sort(v, tmp, mid + 1, right);
		merge(v, tmp, left, right);
	}
}

void start_Merge_Sort(vector<int>& v) {
	vector<int> tmp(v.size());

	merge_Sort(v, tmp, 0, v.size() - 1);
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

	start_Merge_Sort(vec);

	print_Result(vec);

	return 0;
}