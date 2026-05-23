#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N = 0;

bool submitCard(unordered_set<int>& inCards)
{
    for(auto it = inCards.begin(); it != inCards.end();)
    {
        const int card = *it;
        const int anotherCard = N+1-card;
        
        auto targetIt = inCards.find(anotherCard);
        if (targetIt != inCards.end())
        {
            inCards.erase(targetIt);
            it = inCards.erase(it);
            return true;
        }
        
        it++;
    }
    
    return false;
}

bool isNeedAnotherCard(unordered_set<int>& inCards, const int card)
{
    const int anotherCard = (N+1) - card;
    if (inCards.find(anotherCard) != inCards.end())
    {
        return true;
    }
    
    return false;
}

int solution(int coin, vector<int> cards) 
{
    // 초기화
    unordered_set<int> currCards{};
    unordered_set<int> savedCards{};
    N = cards.size();
    for (int i=0; i<N/3; ++i)
    {
        currCards.insert(cards[i]);
    }
    
    // 최선의 카드 뽑기
    int answer = 1;
    int usedCoin = 0;
    for (int i=N/3; i<N; i+=2)
    {
        savedCards.insert(cards[i]);
        savedCards.insert(cards[i+1]);
        answer++;
        
        // 코인 0개
        if (submitCard(currCards))
        {
            continue;
        }
        
        // 코인 1개 (수정된 부분)
        bool isOneCoinUsed = false;
        if (usedCoin + 1 <= coin)
        {
            // 내 기본 카드 중에서 장바구니(savedCards)에 짝이 있는지 전체 검사
            for (auto it = currCards.begin(); it != currCards.end(); ++it)
            {
                int target = (N + 1) - *it;
                if (savedCards.find(target) != savedCards.end())
                {
                    savedCards.erase(target);
                    currCards.erase(it);
                    usedCoin++;
                    isOneCoinUsed = true;
                    break;
                }
            }
        }
        if (isOneCoinUsed)
        {
            continue;
        }
        
        // 코인 2개
        if (usedCoin + 2 <= coin)
        {
            if(submitCard(savedCards))
            {
                usedCoin+=2;
                continue;
            }
        }
        
        answer--;
        break;
    }

    return answer;
}