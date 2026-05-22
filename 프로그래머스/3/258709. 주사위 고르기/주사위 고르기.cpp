#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void GenerateDiceCombo(const vector<vector<int>>& dice, const int n, 
                       vector<int>& currDices, const int idx,
                       vector<vector<int>>& outDicesA, vector<vector<int>>& outDicesB)
{
    if (currDices.size() >= n)
    {
        outDicesA.push_back(currDices);
        
        vector<bool> check(n*2, false);
        for (int i=0; i<n; ++i)
        {
            check[currDices[i]] = true;
        }
        
        vector<int> tmpB{};
        for (int i=0; i<n*2; ++i)
        {
            if (check[i] == false)
            {
                tmpB.push_back(i);
            }
        }
        outDicesB.push_back(tmpB);
        
        return;
    }
    
    if (idx >= n * 2)
    {
        return;
    }
    
    for (int i=idx; i<n*2; ++i)
    {
        currDices.push_back(i);
        GenerateDiceCombo(dice, n, currDices, i+1, outDicesA, outDicesB);
        currDices.pop_back();
    }
}

void CalculateSums(const vector<vector<int>>& dice, const vector<int>& chosenDice, 
                   int depth, int currentSum, vector<int>& outSums) 
{
    if (depth == chosenDice.size()) 
    {
        outSums.push_back(currentSum);
        return;
    }
    
    int diceIdx = chosenDice[depth];
    for (int i = 0; i < 6; ++i) 
    {
        CalculateSums(dice, chosenDice, depth + 1, currentSum + dice[diceIdx][i], outSums);
    }
}

void CalculateDiceWar(const vector<vector<int>>& dice,
                      const vector<vector<int>>& dicesA, 
                      const vector<vector<int>>& dicesB,
                      vector<pair<int, vector<int>>>& outResult)
{
    const int size = dicesA.size();
    for (int i=0; i<size; ++i)
    {
        vector<int> sumA{};
        vector<int> sumB{};
        
        CalculateSums(dice, dicesA[i], 0, 0, sumA);
        CalculateSums(dice, dicesB[i], 0, 0, sumB);
        
        sort(sumB.begin(), sumB.end());
        
        int winCount = 0;
        for (const int& a : sumA)
        {
            auto it = lower_bound(sumB.begin(), sumB.end(), a);
            winCount += distance(sumB.begin(), it);
        }
        
        outResult.push_back({winCount, dicesA[i]});
    }
    
    sort(outResult.begin(), outResult.end(), 
         [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b)
         { return a.first > b.first; });
}

vector<int> solution(vector<vector<int>> dice) 
{
    // 주사위 조합 선택
    vector<vector<int>> myDices{};
    vector<vector<int>> enemyDices{};
    vector<int> tmpOrder{};
    GenerateDiceCombo(dice, dice.size()/2, tmpOrder, 0, myDices, enemyDices);
    
    // 주사위 승률판 제작
    vector<pair<int, vector<int>>> result{};
    CalculateDiceWar(dice, myDices, enemyDices, result);
    
    // 결과 추출
    vector<int> answer = result[0].second;
    sort(answer.begin(), answer.end(), less<int>());
    for(int i = 0; i < answer.size(); ++i) 
    {
        answer[i] += 1;
    }
    
    return answer;
}