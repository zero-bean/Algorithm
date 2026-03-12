#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, r = 0, c = 0;

bool isInRange(const int y, const int x, const int length) { return r >= y && r < y + length && c >= x && c < x + length; }

void recursionZ(int cy, int cx, int cnt, int sz)
{
	if (isInRange(cy, cx, sz) == false)
	{
		return;
	}

	if (cy == r && cx == c)
	{
		cout << cnt << endl;
		return;
	}

	int half = sz / 2;
	recursionZ(cy, cx, cnt, half);
	recursionZ(cy, cx + half, cnt + half * half, half);
	recursionZ(cy + half, cx, cnt + 2 * half * half, half);
	recursionZ(cy + half, cx + half, cnt + 3 * half * half, half);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r >> c;

	int whole = static_cast<int>(pow(2, n));
	recursionZ(0, 0, 0, whole);

	return 0;
}