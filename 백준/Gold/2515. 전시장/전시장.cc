#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Picture
{
	Picture(const int inCost, const int inHeight) : cost(inCost), height(inHeight) {}
	Picture() {}

	int cost = 0;
	int height = 0;
};

vector<Picture> Pictures{};
vector<int> MaxValue{};
int N = 0, S = 0;

int BinarySearch(int left, int right, const int impact)
{
	int resultIdx = -1;

	while (left <= right)
	{
		
		int mid = (left + right) / 2;
		const int threshold = impact - Pictures[mid].height;
		
		if (threshold < S)
		{
			right = mid - 1;
		}
		else
		{
			resultIdx = mid;
			left = mid + 1;
		}
	}

	return resultIdx;
}

void Solve()
{
	MaxValue[0] = Pictures[0].cost;

	for (int i = 1; i < N; ++i)
	{
		const int idx = BinarySearch(0, i - 1, Pictures[i].height);
		const int selected = Pictures[i].cost + (idx == -1 ? 0 : MaxValue[idx]);

		const int notSelected = MaxValue[i - 1];
		
		MaxValue[i] = max(selected, notSelected);
	}

	cout << MaxValue[N - 1] << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	MaxValue.resize(N, 0);
	Pictures.resize(N);
	for (auto& picture : Pictures)
	{
		cin >> picture.height >> picture.cost;
	}

	sort(Pictures.begin(), Pictures.end(), [](const Picture& a, const Picture& b)
		{
			if (a.height == b.height)
			{
				return a.cost < b.cost;
			}

			return a.height < b.height;
		});

	Solve();

	return 0;
}