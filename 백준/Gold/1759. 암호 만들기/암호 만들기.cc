#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L, C;

vector<char> Alphabets;
vector<char> Password;

void CheckPassword(int& OutVowelCount, int& OutConsonantCount)
{
	for (char& Alphabet : Password)
	{
		if (Alphabet == 'a' || Alphabet == 'e' || Alphabet == 'i' || Alphabet == 'o' || Alphabet == 'u')
		{
			OutVowelCount++;
		}
		else
		{
			OutConsonantCount++;
		}
	}
}

void Solve(int PasswordIdx, int AlphabetIdx)
{
	if (PasswordIdx == L)
	{
		int VowelCount = 0;
		int ConsonantCount = 0;
		CheckPassword(VowelCount, ConsonantCount);

		if (VowelCount >= 1 && ConsonantCount >= 2)
		{
			cout << string(Password.begin(), Password.end()) << endl;
		}

		return;
	}

	for (int i = AlphabetIdx; i < C; ++i)
	{
		Password[PasswordIdx] = Alphabets[i];
		Solve(PasswordIdx + 1, i + 1);
	}
}

int main(void)
{
	cin >> L >> C;

	Password.assign(L, NULL);
	Alphabets.assign(C, NULL);
	for (char& Alphabet : Alphabets)
	{
		cin >> Alphabet;
	}

	// 사전 순으로 정렬
	std::sort(Alphabets.begin(), Alphabets.end(), [](const char A, const char B) -> bool {return A < B; });

	Solve(0, 0);

	return 0;
}