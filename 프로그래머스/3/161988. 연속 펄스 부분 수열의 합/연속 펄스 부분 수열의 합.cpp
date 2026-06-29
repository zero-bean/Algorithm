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
        if (vec[i] >= 0)
        {
            tmpValue += vec[i];
            maxValue = max(tmpValue, maxValue);
        }
        else
        {
            // 현재 원소를 넣었을 때 총 값이 0 미만이면, 새로하는 것이 베스트임
            if (tmpValue + vec[i] < 0)
            {
                maxValue = max(maxValue, tmpValue);
                tmpValue = 0;
                continue;
            }
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