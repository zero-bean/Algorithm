#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int answer=0;

    for (int i=0; i<s.size(); ++i)
    {
        int left = i;
        int right = i;
        
        while (left >= 0 && right < s.size())
        {
            if (s[left] != s[right]) { break; }
            
            answer = max(answer, right - left + 1);
            left--;
            right++;
        }
        
        left = i;
        right = i+1;
                
        while (left >= 0 && right < s.size())
        {
            if (s[left] != s[right]) { break; }
            
            answer = max(answer, right - left + 1);
            left--;
            right++;
        }
    }

    return answer;
}