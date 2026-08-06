#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) 
{   
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b)
         {
             return a[1] < b[1];
         });
 
    int answer = 1;
    int threshold = routes[0][1];
    for (int i=1; i<routes.size(); ++i)
    {
        if (threshold < routes[i][0])
        {
            threshold = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}