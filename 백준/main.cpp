#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> Switches{};
vector<int> Orders{};
int N = 0;

int BinarySearch(const vector<int>& arr, const int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (target <= arr[mid])
        {
            result = mid;
            right = mid - 1;
        }
        else if (target > arr[mid])
        {
            left = mid + 1;
        }
    }

    return result;
}

void Solve()
{
    vector<int> Answers{};
    Answers.push_back(Orders[1]);
    
    for (int i = 2; i <= N; ++i)
    {
        if (Answers.back() < Orders[i])
        {
            Answers.push_back(Orders[i]);
        }
        else
        {
            int changedIdx = BinarySearch(Answers, Orders[i]);
            Answers[changedIdx] = Orders[i];
        }
    }

    cout << Orders.size() << "\n";
    for (const auto& answer : Answers)
    {
        cout << answer << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    Switches.resize(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        int input = 0;
        cin >> input;
        Switches[input] = i;
    }

    Orders.resize(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        int input = 0;
        cin >> input;
        Orders[Switches[input]] = i;
    }
    
    Solve();

    return 0;
}