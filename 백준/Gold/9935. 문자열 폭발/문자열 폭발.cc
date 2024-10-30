#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

stack<char> s;
string str;
string bomb;

bool IsEqual(string tmp) { return tmp == bomb; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str >> bomb;
	
	const int bSize = bomb.size();
	string res;

	for (int i = 0; i < str.size(); i++) {
		s.push(str[i]);

		if (s.top() == bomb.back() && s.size() >= bSize) {
			string tmp;

			for (int j = 0; j < bSize; j++) {
				tmp.push_back(s.top());
				s.pop();
			}

			reverse(tmp.begin(), tmp.end());

			if (IsEqual(tmp))
				continue;

			for (int j = 0; j < tmp.size(); j++)
				s.push(tmp[j]);
		}
	}

	while (!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}

	reverse(res.begin(), res.end());

	str = res;


	if (str.empty())
		cout << "FRULA" << endl;
	else
		cout << str << endl;

	return 0;
}