#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int binarySearch(const vector<pair<ll, ll>>& v, const ll target) 
{
    int left = 0, right = v.size() - 1;
    while (left <= right) 
    {
        const int mid = left + (right - left) / 2;
        
        if (target < v[mid].first)
        {
            right = mid - 1;
        }
        else if (target > v[mid].second)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    
    return -1;
}

vector<long long> solution(vector<int> arr, long long l, long long r) 
{
    const int arrSz = arr.size();
    vector<long long> answer(2, 0);
    l -= 1; r -= 1;

    // brr 만들기
    vector<pair<ll, ll>> indices(arrSz);
    indices[0] = {0, (ll)arr[0] - 1};
    for (int i = 1; i < arrSz; ++i) 
    {
        indices[i].first = indices[i - 1].second + 1;
        indices[i].second = indices[i].first + arr[i] - 1;
    }

    // K값 계산
    const int leftIdx = binarySearch(indices, l);
    const int rightIdx = binarySearch(indices, r);
    ll K = 0;
    if (leftIdx == rightIdx) 
    {
        K = (r - l + 1) * (ll)arr[leftIdx];
    } 
    else 
    {
        K += (indices[leftIdx].second - l + 1) * (ll)arr[leftIdx];
        K += (r - indices[rightIdx].first + 1) * (ll)arr[rightIdx];
        for (int i = leftIdx + 1; i < rightIdx; ++i) 
        {
            K += (ll)arr[i] * arr[i];
        }
    }
    answer[0] = K;

    // C 구하기
    ll windowLen = r - l + 1;
    ll totalBrrSz = indices[arrSz - 1].second + 1;
    ll currentSum = 0;
    int curLIdx = 0;
    int curRIdx = binarySearch(indices, windowLen - 1);

    // 초기 윈도우 [0, windowLen-1] 합
    if (curLIdx == curRIdx) 
    {
        currentSum = windowLen * (ll)arr[curLIdx];
    } 
    else 
    {
        currentSum += (indices[curLIdx].second + 1) * (ll)arr[curLIdx];
        currentSum += (windowLen - 1 - indices[curRIdx].first + 1) * (ll)arr[curRIdx];
        
        for (int i = curLIdx + 1; i < curRIdx; ++i)
        {
            currentSum += (ll)arr[i] * arr[i];
        }
    }

    ll winL = 0;
    while (winL <= totalBrrSz - windowLen) 
    {
        if (curLIdx >= arrSz || curRIdx >= arrSz)
        {
            break;
        }

        ll valL = arr[curLIdx], valR = arr[curRIdx];
        ll distL = indices[curLIdx].second - winL + 1;
        ll distR = indices[curRIdx].second - (winL + windowLen - 1) + 1;
        ll move = min(distL, distR);

        // valL == valR: 이 구간 동안 sum 고정
        if (valL == valR) 
        {
            if (currentSum == K)
            {
                answer[1] += move;
            }
        } 
        else 
        {
            // sum이 매 스텝 (valR-valL)씩 변함
            // currentSum + t*(valR-valL) == K 인 t 찾기
            ll diff = valR - valL;
            ll targetGap = K - currentSum;
            if (targetGap % diff == 0) 
            {
                ll t = targetGap / diff;
                if (t >= 0 && t < move) answer[1] += 1;
            }
        }

        // sum을 move번 이동한 후로 업데이트
        currentSum += move * (valR - valL);
        winL += move;

        if (winL < totalBrrSz) 
        {
            if (winL > indices[curLIdx].second)
            {
                 curLIdx++;
            }

            ll newWinR = winL + windowLen - 1;
            if (newWinR > indices[curRIdx].second)
            {
                curRIdx++;
                // winR 블록이 바뀌었으므로 sum 보정
                currentSum -= (ll)arr[curRIdx - 1];
                currentSum += (ll)arr[curRIdx];
            }
        }
    }

    return answer;
}