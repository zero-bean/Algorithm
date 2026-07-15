#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long binarySearch(const int n, const vector<int>& times)
{
    long long left = 0;
    long long right = static_cast<long long>(times.back()) * n;
    long long answer = -1;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long passedPeople = 0;
        
        for (int i=0; i<times.size(); ++i)
        {
            passedPeople += (mid / times[i]);
        }
        
        if (passedPeople >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return answer;
}

long long solution(int n, vector<int> times) 
{
    sort(times.begin(), times.end(), less<int>());
    
    return binarySearch(n, times);
}