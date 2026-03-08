#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N = 0;

void Hanoi(int Cnt, int Start, int End, int Sub)
{
	if (Cnt == 1)
	{
		cout << Start << " " << End << "\n";
		return;
	}

	Hanoi(Cnt - 1, Start, Sub, End);
	cout << Start << " " << End << "\n";
	Hanoi(Cnt - 1, Sub, End, Start);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cout << static_cast<int>(pow(2, N) - 1) << endl;

	Hanoi(N, 1, 3, 2);

	return 0;
}