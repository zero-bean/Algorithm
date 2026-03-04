#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0, Trials = 0;
vector<bool> IsBroken{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int Num;
		cin >> Num;
		IsBroken[Num] = true;
	}

	Trials = abs(N - 100);

	for (int i = 0; i < 1'000'000; ++i)
	{
		int tmpChannel = i;
		int btnCnt = 0;
		bool isAble = true;
		
		if (i == 0)
		{
			if (IsBroken[0] == true)
			{
				continue;
			}

			btnCnt += 1;
		}
		else
		{
			while (tmpChannel > 0)
			{
				int left = tmpChannel % 10;
				tmpChannel /= 10;
				btnCnt += 1;

				if (IsBroken[left])
				{
					isAble = false;
					break;
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