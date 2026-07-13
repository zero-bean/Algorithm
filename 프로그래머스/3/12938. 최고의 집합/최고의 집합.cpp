#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) 
{
    if (n > s) { return {-1}; }
    
    vector<int> answer(n, 0);
    
    int mod = s / n;
    int divided = s % n;
    
    for (int i=0; i<n; ++i)
    {
        answer[i] = mod;
    }
    
    int idx = 0;
    while (divided > 0)
    {
        answer[idx] += 1;
        divided -= 1;
        idx++;
        
        if (idx >= n) { idx = 0; }
    }
    
    sort(answer.begin(), answer.end(), less<int>());
    
    return answer;
}