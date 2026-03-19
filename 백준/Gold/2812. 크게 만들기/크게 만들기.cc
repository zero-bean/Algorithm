#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N = 0, K = 0;
string NumString{};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K >> NumString;

	deque<int> tokens{};
	deque<int> answer{};
	
	for (char& num : NumString)
	{
		tokens.push_back(num - '0');
	}

	answer.push_back(tokens.front());
	tokens.pop_front();

	while (K > 0 && !tokens.empty())
	{
		while (!answer.empty() && K > 0 && answer.back() < tokens.front())
		{
			answer.pop_back();
			K--;
		}

		answer.push_back(tokens.front());
		tokens.pop_front();
	}

	while (!tokens.empty())
	{
		answer.push_back(tokens.front());
		tokens.pop_front();
	}

	while (K--)
	{
		answer.pop_back();
	}

	while (!answer.empty())
	{
		cout << answer.front();
		answer.pop_front();
	}

	return 0;
}