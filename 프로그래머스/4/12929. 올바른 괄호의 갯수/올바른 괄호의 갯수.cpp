#include <string>
#include <vector>
#include <queue>

using namespace std;

/* 반드시 처음은 (로 시작하고, 마지막은 )로 끝나야 한다. 
* 
*/

void calculate(int& cnt, int maxSize, int left, int right)
{
    // ')'가 '(' 보다 커지면 올바르지 않는 괄호임
    if (right > left) { return; }
    
    if (left <= maxSize) 
    { 
        calculate(cnt, maxSize, left + 1, right);
    }
    
    if (right <= maxSize)
    {
        calculate(cnt, maxSize, left, right + 1);
    }

    if (left == maxSize && right == maxSize)
    {
        cnt++;
        return;
    }
}

int solution(int n) 
{
    int answer = 0;
    int left = 0;
    int right = 0;
    
    calculate(answer, n, left, right);
    
    return answer;
}