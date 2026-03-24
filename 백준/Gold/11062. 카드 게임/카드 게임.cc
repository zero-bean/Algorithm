#include <iostream>
#include <vector>
#include <string>

using namespace std;

int choiceCard(const vector<int>& cards, vector<vector<int>>& score, int left, int right, string turn)
{
	if (left > right)
	{
		return 0;
	}

	if (score[left][right] != 0)
	{
		return score[left][right];
	}

	if (turn == "근우")
	{
		return score[left][right] = max(choiceCard(cards, score, left + 1, right, "명우") + cards[left], choiceCard(cards, score, left, right - 1, "명우") + cards[right]);
	}
	else if (turn == "명우")
	{
		return score[left][right] = min(choiceCard(cards, score, left + 1, right, "근우"), choiceCard(cards, score, left, right - 1, "근우"));
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cases = 0;
	cin >> cases;

	while (cases--)
	{
		int n = 0;
		cin >> n;

		vector<int> cards(n + 1);
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int i = 1; i <= n; ++i)
		{
			cin >> cards[i];
		}

		cout << choiceCard(cards, dp, 1, n, "근우") << "\n";
	}

	return 0;
}