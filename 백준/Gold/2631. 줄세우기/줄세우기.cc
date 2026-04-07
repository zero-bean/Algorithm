#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Child
{
	Child(const int inIdx, const int inScore) : order(inIdx), score(inScore) {}
	Child() {}

	int order = -1;
	int score = -1;
};

int N = 0;
vector<Child> Children{};

int FindChildIdx(const int targetOrder, const int ceiling)
{
	int result = -1;
	int maxScore = -1;

	for (int i = 0; i < ceiling; ++i)
	{
		if (Children[i].order < targetOrder)
		{
			if (Children[i].score > maxScore)
			{
				result = i;
				maxScore = Children[i].score;
			}
		}
	}

	return result;
}

int UpdateScore(const int targetIdx)
{
	if (Children[targetIdx].score == -1)
	{
		const int preChildIndex = FindChildIdx(Children[targetIdx].order, targetIdx);
		if (preChildIndex == -1)
		{
			return Children[targetIdx].score = 0;
		}

		return Children[targetIdx].score = UpdateScore(preChildIndex) + 1;
	}

	return Children[targetIdx].score;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	Children.resize(N);
	for (auto& child : Children)
	{
		cin >> child.order;
		child.order -= 1;

		if (child.order == 0)
		{
			child.score = 0;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		UpdateScore(i);
	}

	sort(Children.begin(), Children.end(), [](const Child& a, const Child& b) { return a.score > b.score; });

	cout << N - Children[0].score - 1 << "\n";

	return 0;
}