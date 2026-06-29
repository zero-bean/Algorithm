#include <string>
#include <vector>

using namespace std;

void initialize(vector<int>& outVectorA, vector<int>& outVectorB)
{
    const int length = outVectorA.size();

    for(int i = 0; i < length; ++i)
    {
        if (i % 2 == 0)
        {
            outVectorA[i] *= -1;
        }
        else
        {
            outVectorB[i] *= -1;
        }
    }
}

long long calculateSums(const vector<int>& vec)
{
    const int length = vec.size();
    long long maxValue = vec[0];
    long long tmpValue = 0;
    for (int i = 0; i < length; ++i)
    {     
        // 검사할 원소가 증가하는 경우는 Best Case이므로, 더하고 maxValue를 갱신하기만 하면 된다.
        if (vec[i] >= 0)
        {
            tmpValue += vec[i];
            maxValue = max(tmpValue, maxValue);
        }
        // 검사할 원소가 감소하는 경우라면 경우의 수를 고려해야 한다.
        else
        {
            // 현재 원소를 넣었을 때 총 값이 0 미만이면, 새로하는 것이 베스트임
            if (tmpValue + vec[i] < 0)
            {
                maxValue = max(maxValue, tmpValue);
                tmpValue = 0;
                continue;
            }
            // 아직은 0보단 크므로, 초기화하여 0부터 시도하는 것보단 N부터 계속 시도하는 것이 낫다.
            else
            {
                tmpValue += vec[i];
                maxValue = max(tmpValue, maxValue);
            }
        }
    }
    
    return max(tmpValue, maxValue);
}

long long solution(vector<int> sequence) 
{
    vector<int> patternA(sequence);
    vector<int> patternB(sequence);
    initialize(patternA, patternB);
    
    long long answer = -100'000;
    answer = max(answer, calculateSums(patternA));
    answer = max(answer, calculateSums(patternB));
    
    return answer;
}