#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node
{
    Node(const string inName, const int inStart, const int inLeft)
        : name(inName), start(inStart), left(inLeft) {}
    
    string name;
    int start;
    int left;
};

vector<string> solution(vector<vector<string>> plans) 
{
    vector<Node> newPlan;
    for (const auto& plan : plans)
    {
        int hour = stoi(plan[1].substr(0, 2));
        int Min = stoi(plan[1].substr(3, 2));
        int time = hour * 60 + Min;
        int left = stoi(plan[2]);
        newPlan.push_back({plan[0], time, left});
    }
         
    // 시간 순으로 정렬
    sort(newPlan.begin(), newPlan.end(), [](const Node& a, const Node& b){ 
        return a.start < b.start; 
    });
    
    vector<string> answer;
    stack<Node> leftTasks;
    int currStart = 0;
    
    // 시간 순서대로 과제 하나씩 확인
    for (int i = 0; i < newPlan.size(); ++i)
    {
        Node nextTask = newPlan[i];
        
        // 다음 과제 시작 전까지 시간이 남고, 멈춰둔 과제가 있다면 처리
        while (!leftTasks.empty() && currStart < nextTask.start)
        {
            Node topTask = leftTasks.top();
            leftTasks.pop();
            
            // 멈춰둔 과제를 다음 과제 시작 전에 끝낼 수 있는 경우
            if (currStart + topTask.left <= nextTask.start)
            {
                currStart += topTask.left;
                answer.push_back(topTask.name); 
            }
            // 멈춰둔 과제를 다 못 끝내고 다시 멈춰야 하는 경우
            else
            {
                topTask.left -= (nextTask.start - currStart);
                leftTasks.push(topTask);
                currStart = nextTask.start; 
                break;
            }
        }
        
        // 새로운 과제 시작
        leftTasks.push(nextTask);
        currStart = nextTask.start;
    }
    
    while (!leftTasks.empty())
    {
        answer.push_back(leftTasks.top().name);
        leftTasks.pop();
    }
    
    return answer;
}