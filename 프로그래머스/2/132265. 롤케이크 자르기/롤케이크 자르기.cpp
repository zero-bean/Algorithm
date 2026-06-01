#include <string>
#include <vector>
#include <set>

using namespace std;

void initialize(const vector<int>& topping, vector<int>& outA, vector<int>& outB)
{
    vector<int> history(10'001, false);
    
    history[topping[0]] = true;
    outA[0] = 1;
    for (int i=1; i<outA.size(); ++i)
    {
        if (history[topping[i]] == false)
        {
            history[topping[i]] = true;
            outA[i] = outA[i-1] + 1;
        }
        else
        {
            outA[i] = outA[i-1];
        }
    }
        
    const int size = topping.size() - 1;
    history = vector<int>(10'001, false);
    history[topping[size]] = true;
    outB[size] = 1;
    for (int i=size-1; i>=0; --i)
    {
        if (history[topping[i]] == false)
        {
            history[topping[i]] = true;
            outB[i] = outB[i+1] + 1;
        }
        else
        {
            outB[i] = outB[i+1];
        }
    }
}

int solution(vector<int> topping) 
{
    set<int> checkTopping;
    for (const auto& t : topping)
    {
        checkTopping.insert(t);
    }
    
    const int toppingCount = checkTopping.size();
    
    vector<int> forward(topping.size(), 0);
    vector<int> backward(topping.size(), 0);
    initialize(topping, forward, backward);
    
    int answer = 0;
    for (int i=0; i<topping.size() - 1; ++i)
    {
        if (forward[i] == backward[i+1])
        {
            answer++;
        }
    }
        
    return answer;
}