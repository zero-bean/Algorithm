#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, Good = 0;
vector<int> Nums{};

bool BinarySearch(int left, int right, const int target, const int banNum1, const int banNum2)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (Nums[mid] == target)
		{
			if (mid == banNum1 || mid == banNum2)
			{
				int tmpIndex1 = mid;
				int tmpIndex2 = mid;
				while (Nums[tmpIndex1] == Nums[mid])
				{
					tmpIndex1--;
					if (tmpIndex1 < 0)
					{
						return false;
					}

					if (Nums[tmpIndex1] == Nums[mid] && tmpIndex1 != banNum1 && tmpIndex1 != banNum2)
					{
						return true;
					}
				}

				while (Nums[tmpIndex2] == Nums[mid])
				{
					tmpIndex2++;
					if (tmpIndex2 >= N)
					{
						return false;
					}

					if (Nums[tmpIndex2] == Nums[mid] && tmpIndex2 != banNum1 && tmpIndex2 != banNum2)
					{
						return true;
					}
				}
			}
			else if (mid != banNum1 && mid != banNum2)
			{
				return true;
			}

			return false;
		}
		else if (Nums[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	Nums.resize(N);
	for (auto& num : Nums)
	{
		cin >> num;
	}

	sort(Nums.begin(), Nums.end(), less<int>());

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			int anotherNum = Nums[i] - Nums[j];
			if (BinarySearch(0, N - 1, anotherNum, i, j))
			{
				Good++;
				break;
			}
		}
	}

	cout << Good << endl;

	return 0;
}