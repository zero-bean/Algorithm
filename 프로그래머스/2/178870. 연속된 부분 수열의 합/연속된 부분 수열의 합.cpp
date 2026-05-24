#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    // 초기화
    const int arrSize = sequence.size();
    vector<int> prefixSum(arrSize+1, 0);
    prefixSum[1] = sequence[0];
    for (int i=1; i<=arrSize; ++i)
    {
        prefixSum[i] = prefixSum[i-1] + sequence[i-1];
    }
    
    vector<vector<int>> candidates{};
    int left = 0;
    int right = 1;
    while (right <= arrSize)
    {
        const int value = prefixSum[right] - prefixSum[left];
        
        if (value == k)
        {
            candidates.push_back({left, right - 1});
            left++;
            right++;
        }
        else if (value > k)
        {
            left++;
        }
        else
        {
            right++;
        }
    }
    
    sort(candidates.begin(), candidates.end(), 
         [](const vector<int>& a, const vector<int>& b) 
         { 
             if (a.back() - a[0] == b.back() - b[0])
             {
                 return a[0] < b[0];
             }
             
             return a.back() - a[0] < b.back() - b[0]; 
         });
    return candidates[0];
}