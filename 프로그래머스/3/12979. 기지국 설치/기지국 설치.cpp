#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int start = 1;
    int end = stations[0] - w - 1;
    int length;
    if (start <= end)
    {
        length = end - start + 1;
        answer += ((length - 1) / (2 * w + 1) + 1);
    }
    
    const int size = stations.size();
    for (int i=0; i+1<size; ++i)
    {
        start = stations[i] + w + 1;
        end = stations[i+1] - w - 1;
        
        if (start > end) { continue; }
        
        length = end - start + 1;
        answer += ((length - 1) / (2 * w + 1) + 1);
    }
    
    start = stations.back() + w + 1;
    end = n;
    if (start <= end)
    {
        length = end - start + 1;
        answer += ((length - 1) / (2 * w + 1) + 1);
    }
    

    return answer;
}