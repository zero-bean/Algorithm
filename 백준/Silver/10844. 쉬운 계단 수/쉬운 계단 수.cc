#include <iostream>
#include <vector>

using namespace std;

int N = 0;
vector<vector<int>> Answers{};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	Answers.resize(N + 1, vector<int>(10, 0));

	// N == 0
	for (int i = 0; i <= 9; ++i)
	{
		Answers[0][i] = 0;
	}

	// N == 1
	for (int i = 0; i <= 9; ++i)
	{
		Answers[1][i] = 1;
	}
	Answers[1][0] = 0;

	// N >= 2
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
			{
				Answers[i][j] = Answers[i - 1][j + 1] % 1'000'000'000;
			}
			else if (j == 9)
			{
				Answers[i][j] = Answers[i - 1][j - 1] % 1'000'000'000;
			}
			else
			{
				Answers[i][j] = (Answers[i - 1][j + 1] + Answers[i - 1][j - 1]) % 1'000'000'000;
			}
		}
	}

	for (int i = 1; i <= 9; ++i)
	{
		Answers[N][i] = (Answers[N][i] + Answers[N][i - 1]) % 1'000'000'000;
	}

	cout << Answers[N][9] << endl;

	return 0;
}