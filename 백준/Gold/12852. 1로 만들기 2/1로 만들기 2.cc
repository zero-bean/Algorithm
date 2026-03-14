#include <iostream>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int> DP(N +1, numeric_limits<int>::max());
	vector<int> tracer(N + 1, -1);
	stack<int> s;

	DP[N] = 0;

	for (int i = N; i > 0; --i)
	{
		if (i % 3 == 0)
		{
			if (DP[i] + 1 < DP[i / 3])
			{
				DP[i / 3] = DP[i] + 1;
				tracer[i / 3] = i;
			}
		}

		if (i % 2 == 0)
		{
			if (DP[i] + 1 < DP[i / 2])
			{
				DP[i / 2] = DP[i] + 1;
				tracer[i / 2] = i;
			}
		}

		if (DP[i] + 1 < DP[i - 1])
		{
			DP[i - 1] = DP[i] + 1;
			tracer[i - 1] = i;
		}
	}

	cout << DP[1] << endl;
	
	s.push(1);
	for (int i = 1; tracer[i] != -1; i = tracer[i])
	{
		s.push(tracer[i]);
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}