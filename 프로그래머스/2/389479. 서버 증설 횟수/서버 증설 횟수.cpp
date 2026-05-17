#include <string>
#include <vector>
using namespace std;

int solution(vector<int> players, int m, int k)
{
    int answer = 0;
    vector<int> usedServer(players.size(), 0);
    
    const int sz = players.size();
    for (int i = 0; i < sz; ++i)
    {
        // 서버 증설이 필요하지 않는 경우 생략
        if (players[i] < (usedServer[i] + 1) * m)
        {
            continue;
        }
        
        // 서버 증설이 필요한 경우
        const int leftUser = players[i] - usedServer[i] * m;
        
        // 필요한 서버 수 계산
        int mod = leftUser / m;
            
        // 서버 가용 시간까지 계산
        for (int j = i; j < i + k; ++j)
        {
            if (j >= sz)
            {
                break;
            }

            usedServer[j] += mod;
        }
        
        answer += mod;
    }
    
    return answer;
}