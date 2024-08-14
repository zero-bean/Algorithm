#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <vector>

using namespace std;

vector<int> nums(6, 0);
string origin;
int answer;

map<char, int> initialize_Map() {
	map<char, int> my_Map;
	char alphabets[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	for (int i = 0; i < 6; i++) 
		my_Map.insert({ alphabets[i], nums[i] });
	
	return my_Map;
}

void calculate() {
	map<char, int> m = initialize_Map();
	int tot = m[origin[0]];

	for (int i = 1; i < origin.size(); i+=2) {
		int num = m[origin[i + 1]];

		if (origin[i] == '*')
			tot = tot * num;
		else if (origin[i] == '+')
			tot = tot + num;
		else if (origin[i] == '-')
			tot = tot - num;
	}

	answer = max(tot, answer);
}

void generate_Combination(int curr_idx) {
	if (curr_idx >= nums.size()) {
		calculate();
		return;
	}

	for (int i = 1; i <= 4; i++) {
		nums[curr_idx] = i;
		generate_Combination(curr_idx + 1);
	}
}

void solve() {
	answer = numeric_limits<int>::min();

	generate_Combination(0);

	cout << answer << endl;
}

int main() {
	cin >> origin;

	solve();

	return 0;
}