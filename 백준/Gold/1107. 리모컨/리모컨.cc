#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0, Trials = 0;
vector<int> BrokenBtn{};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	BrokenBtn.resize(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> BrokenBtn[i];
	}

	Trials = abs(N - 100);

	for (int i = 0; i < 1'000'000; ++i)
	{
		int tmpChannel = i;
		int btnCnt = 0;
		bool isAble = true;
		
		if (i == 0)
		{
			for (int j = 0; j < M; ++j)
			{
				if (i == BrokenBtn[j])
				{
					isAble = false;
					break;
				}
			}

			if (isAble)
			{
				btnCnt = 1;
			}
		}
		else
		{
			while (tmpChannel > 0)
			{
				int left = tmpChannel % 10;
				tmpChannel /= 10;
				btnCnt += 1;

				for (int j = 0; j < M; ++j)
				{
					if (left == BrokenBtn[j])
					{
						isAble = false;
						break;
					}
				}
			}
		}

		if (isAble)
		{
			Trials = min(Trials, abs(i - N) + btnCnt);
		}
	}

	cout << Trials << endl;

	return 0;
}