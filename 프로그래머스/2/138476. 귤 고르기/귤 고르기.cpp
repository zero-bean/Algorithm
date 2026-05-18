#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    unordered_map<int, int> tangerineInfo{};

    for (const auto& tgr : tangerine)
    {
        tangerineInfo[tgr]++;
    }

    vector<int> result{};
    for (const auto tangerine : tangerineInfo)
    {
        result.push_back(tangerine.second);
    }

    sort(result.begin(), result.end(), greater<int>());

    for (int i = 0; i < result.size(); ++i)
    {
        if (k <= 0)
        {
            break;
        }

        k -= result[i];
        answer++;
    }

    return answer;
}