#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str1;
string str2;

void LCS() {
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
	vector<char> ans;
	int tot = 0;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}

	tot = dp[str1.size()][str2.size()];

	int lastPos = str2.size();
	int size = tot;
	for (int i = str1.size(); i >= 1; i--) {
		if (lastPos < 1)
			lastPos = 1;
		for (int j = lastPos; j >= 1; j--) {
			if (dp[i][j] == size && str1[i - 1] == str2[j - 1]) {
				ans.push_back(str1[i - 1]);
				lastPos = j-1;
				size -= 1;
				break;
			}
		}
	}

	cout << tot << endl;

	if (tot != 0) {
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i];
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str1 >> str2;

	LCS();

	return 0;
}