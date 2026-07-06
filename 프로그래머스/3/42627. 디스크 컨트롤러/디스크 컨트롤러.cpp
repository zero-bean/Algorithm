#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) 
{
    auto diskSort = [](const vector<int>& a, const vector<int>& b) {
        return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(diskSort)> pq(diskSort);    
    
    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    
    queue<vector<int>> leftTasks;
    for (int i=0; i<jobs.size(); ++i)
    {
        leftTasks.push(jobs[i]);
    }
    
    int answer = 0;
    int time = 0;
    while (!(leftTasks.empty() && pq.empty()))
    {
        // 작업이 남아있고, 해당 시점에 작업 요청이 존재하면, pq에 추가합니다.
        while (!leftTasks.empty() && leftTasks.front()[0] <= time)
        {
            pq.push(leftTasks.front());
            leftTasks.pop();
        }
        
        // 처리할 업무가 없다면 생략
        if(pq.empty())
        {
            time++;
            continue;
        }
        
        // 처리 시도
        const vector<int> task = pq.top();
        time += task[1];
        pq.pop();
        
        // 답 계산
        answer += (time - task[0]);
    }
    
    return answer / jobs.size();
}