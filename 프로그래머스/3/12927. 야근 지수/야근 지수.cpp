#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) 
{
    sort(works.begin(), works.end(), [](const int a, const int b){ return a > b; });
    
    int total = 0;
    for (int i=0; i<works.size(); ++i)
    {
        total += works[i];    
    }
    
    int leftValue = total - n;
    if (leftValue <= 0) { return 0; }
    
    vector<int> result(works.size(), 0);
    while (leftValue > 0)
    {
        for (int i=0; i< works.size() && leftValue > 0; ++i)
        {
            if (result[i] < works[i])
            {
                result[i] += 1;
                leftValue -= 1;
            }
        }
    }

        
    long long answer = 0;
    for (const int& leftWork : result)
    {
        answer += (leftWork * leftWork);
    }
    
    return answer;
}