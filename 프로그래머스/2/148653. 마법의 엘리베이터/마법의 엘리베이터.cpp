#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) 
{
    int answer = 0;
    
    while(storey > 0)
    {
        if (storey < 10)
        {
            if (storey > 5)
            {
                answer += (1 + (10 - storey));
                break;
            }
            else
            {
                answer += storey;
                break;
            }
        }
        
        const string strStorey = to_string(storey);
        const int mod = strStorey.size() - 1;
        const int mostLeftNum = strStorey[0] - '0';

        if (mostLeftNum > 5)
        {
            storey = abs(storey-pow(10, mod+1));
            answer += 1;
        }
        else if (mostLeftNum < 5)
        {
            storey = storey - (pow(10, mod) * mostLeftNum);
            answer += (mostLeftNum);
        }
        else if (mostLeftNum == 5)
        {
            const int nextNum = strStorey[1] - '0';
            const bool isDown = nextNum < 5; 
            if (isDown)
            {
                storey = storey - (pow(10, mod) * mostLeftNum);
                answer += (mostLeftNum);
            }
            else
            {
                storey = abs(storey-pow(10, mod+1));
                answer += 1;
            }
        }
        
    }
    
    return answer;
}