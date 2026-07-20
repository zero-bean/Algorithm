#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    map<string, int> data;
    for (int i=0; i<genres.size(); ++i)
    {
        data[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> lists;
    for (const auto d : data)
    {
        lists.push_back(d);
    }
    sort(lists.begin(), lists.end(), [](const pair<string, int>& a, const pair<string, int>& b)
         { return a.second > b.second; });
    
    vector<int> answer;
    for (const auto& d : lists)
    {
        // 특정 장르만 모은다
        vector<pair<int, int>> filter;
        for (int i=0; i<genres.size(); ++i)
        {
            if (genres[i] == d.first)
            {
                filter.push_back({i, plays[i]});
            }
        }
        
        // 재생 횟수 기준으로 내림차순 정렬
        sort(filter.begin(), filter.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b)
             { 
                 return a.second > b.second; 
             });
        
        // 최대 두 개만 추출하여 삽입
        if (filter.size() >= 2)
        {
            answer.push_back(filter[0].first);
            answer.push_back(filter[1].first);
        }
        else
        {
            answer.push_back(filter[0].first);
        }
    }
        
    return answer;
}