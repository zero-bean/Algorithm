#include <iostream>
#include <vector>

using namespace std;

int N;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	while (N--)
	{
		int B = 1;
		cin >> B;

		vector<vector<int>> btn(B + 1, vector<int>(B + 1, 0));
		for (int i = 0; i <= B; ++i)
		{
			btn[i][0] = 1; // N개 중에서 0개를 고르는 경우는 무조건 1 == '누르지 않는다'
			btn[i][i] = 1; // N개 중에서 N개를 고르는 경우는 무조건 1 == '전부 누른다'
		}

		vector<long long> ways(B + 1, 0);
		
		for (int n = 1; n <= B; ++n)
		{
			for (int k = 1; k <= n; ++k)
			{
				// [N개 중 K개 선택] = [N-1개 중 K-1개 선택] + [N-1개 중 K개 선택]
				btn[n][k] = btn[n - 1][k - 1] + btn[n - 1][k];

				// N개 중에 K개를 선택했으므로, 남아있는 버튼의 수는 N - K개가 된다.
				ways[n] += btn[n][k] * (ways[n - k] + 1);
			}
		}

		cout << ways[B] << "\n";
	}

	return 0;
}