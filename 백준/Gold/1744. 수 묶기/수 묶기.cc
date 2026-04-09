#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> Negatives{};
priority_queue<int, vector<int>, less<int>> Positives{};
queue<int> Zeros{};
int N = 0;

void Solve()
{
	long long answer = 0;

	while (Negatives.size() > 1)
	{
		int first = Negatives.top();
		Negatives.pop();
		int second = Negatives.top();
		Negatives.pop();

		answer += static_cast<long long>(first * second);
	}

	while (!Zeros.empty() && !Negatives.empty())
	{
		Zeros.pop();
		Negatives.pop();
	}

	// 0이 없어서 음수 처리가 안되었을 수도.
	if (!Negatives.empty())
	{
		answer += Negatives.top();
		Negatives.pop();
	}

	while (Positives.size() > 1)
	{
		int first = Positives.top();
		Positives.pop();
		int second = Positives.top();
		Positives.pop();

		if (first == 1 || second == 1)
		{
			answer += static_cast<long long>(first + second);
		}
		else
		{
			answer += static_cast<long long>(first * second);
		}
	}

	if (Positives.empty() == false)
	{
		answer += static_cast<long long>(Positives.top());
	}

	cout << answer << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		if (input > 0)
		{
			Positives.push(input);
		}
		else if (input < 0)
		{
			Negatives.push(input);
		}
		else if (input == 0)
		{
			Zeros.push(input);
		}
	}

	Solve();

	return 0;
}