#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    unordered_set<string> history{};
    
    for (const auto& phone : phone_book)
    {
        history.insert(phone);
    }
    
    sort(phone_book.begin(), phone_book.end());
    
    const int phoneBookSz = phone_book.size();
    for (int i=0; i<phoneBookSz; ++i)
    {
        const string phone = phone_book[i];
        const int phoneSz = phone.size();
        
        string targetNumber{};
        for (int j=0; j<phoneSz - 1; ++j)
        {
            targetNumber += phone[j];
            if (history.find(targetNumber) != history.end())
            {
                answer = false;
                return answer;
            }
        }
    }
    
    return answer;
}