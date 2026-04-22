#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) 
{
    int answer = -1;
    const int coworkerSize = scores.size();
    const vector<int> target = scores[0];
    const int targetSum = target[0] + target[1];
    
    // 근무태도 내림차순, 같으면 동료평가 오름차순
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b)
         { if(a[0] == b[0]) { return a[1] < b[1]; }  return a[0] > b[0]; });
    
    int maxPeer = 0;       // 지금까지 본 동료평가 최댓값
    int rank = 1;          // 완호의 등수
    
    for (int i = 0; i < coworkerSize; ++i)
    {
        const vector<int>& curr = scores[i];
        
        // 제외 대상 판정: 앞에 근무태도가 엄격히 큰 사람 중 동료평가도 더 큰 사람이 있음
        if (curr[1] < maxPeer)
        {
            // 완호가 제외 대상이면 -1
            if (curr == target)
            {
                return -1;
            }
            continue;
        }
        
        maxPeer = curr[1];
        
        // 제외되지 않은 사람 중 완호보다 점수 합계가 큰 사람을 카운트
        if (curr != target && curr[0] + curr[1] > targetSum)
        {
            rank++;
        }
    }
    
    return rank;
}