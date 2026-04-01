#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> marbles{};
vector<int> orders{};
int N = 0, M = 0;

int binarySearch(int low, int high)
{
	if (low > high)
	{
		return low;
	}

	int groupCnts = 0;
	int mid = (low + high) / 2;
	int threshold = 0;
	int marbleCntInGroup = 0;

	for (const auto& marble : marbles)
	{
		if (threshold + marble > mid)
		{
			groupCnts++;
			threshold = 0;
			marbleCntInGroup = 0;
		}

		threshold += marble;
		marbleCntInGroup += 1;
	}

	if (marbleCntInGroup != 0)
	{
		groupCnts++;
	}

	// M개 이하의 그룹이 만들어졌다는 것은 그룹의 임계점이 넉넉하여 기준치를 낮춰도 됨
	if (groupCnts <= M)
	{
		return binarySearch(low, mid - 1);
	}
	// M개 초과하여 그룹이 만들어졌다는 것은 그룹의 임계점이 낮아서 기준치를 높여야 함
	else
	{
		return binarySearch(mid + 1, high);
	}
}

void divideGroup(const int threshold)
{
	vector<int> result{};
	int leftGroupCnt = M;
	int groupValue = 0;
	int marbleCntInGroup = 0;

	for (int i = 0; i < N; ++i)
	{
		if (groupValue + marbles[i] > threshold)
		{
			result.push_back(marbleCntInGroup);
			groupValue = 0;
			marbleCntInGroup = 0;
			leftGroupCnt -= 1;
		}

		groupValue += marbles[i];
		marbleCntInGroup += 1;

		if (leftGroupCnt == N - i)
		{
			result.push_back(marbleCntInGroup);
			marbleCntInGroup = 0;
			leftGroupCnt -= 1;

			while (leftGroupCnt--)
			{
				result.push_back(1 + marbleCntInGroup);
				marbleCntInGroup = 0;
			}

			break;
		}
	}

	cout << threshold << "\n";
	for (const auto& groupCnt : result)
	{
		cout << groupCnt << " ";
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int lowValue = 0;
	int highValue = 0;

	cin >> N >> M;

	orders.resize(M);
	marbles.resize(N);
	for (auto& marble : marbles)
	{
		cin >> marble;

		highValue += marble;

		if (lowValue < marble)
		{
			lowValue = marble;
		}
	}

	int res = binarySearch(lowValue, highValue);

	divideGroup(res);

	return 0;
}