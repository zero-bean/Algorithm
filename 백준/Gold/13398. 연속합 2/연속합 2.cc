#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> NormalCases{};
vector<int> DeletedCases{};
vector<int> Nums{};
int N = 0;

void Solve()
{
    int NormalMaxValue = Nums[0];
    int DeletedMaxValue = Nums[0];

    for (int i = 1; i < N; ++i)
    {
        // Normal
        NormalCases[i] = max(NormalCases[i - 1] + Nums[i], Nums[i]);

        // Delete
        DeletedCases[i] = max(NormalCases[i - 1], DeletedCases[i - 1] + Nums[i]);

        NormalMaxValue = max(NormalMaxValue, NormalCases[i]);
        DeletedMaxValue = max(DeletedMaxValue, DeletedCases[i]);
    }

    cout << max(NormalMaxValue, DeletedMaxValue);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    DeletedCases.resize(N);
    Nums.resize(N);
    NormalCases.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Nums[i];
    }

    NormalCases[0] = Nums[0];
    DeletedCases[0] = 0;

    Solve();

    return 0;
}