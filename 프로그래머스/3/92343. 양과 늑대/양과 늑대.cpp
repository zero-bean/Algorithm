#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Graph{};
vector<int> Info{};

void search(int& answer, int idx, int wolf, int lamb, vector<int> nextNodes)
{
    Info[idx] == 0 ? lamb++ : wolf++;
    
    if (wolf >= lamb) { return; }
    
    if (answer < lamb) { answer = lamb; }
    
    for (const auto& child : Graph[idx])
    {
        nextNodes.push_back(child);
    }
    
    for (int i=0; i<nextNodes.size(); ++i)
    {
        vector<int> newNextNodes = nextNodes;
        newNextNodes.erase(newNextNodes.begin() + i);
        search(answer, nextNodes[i], wolf, lamb, newNextNodes);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) 
{
    // 탐색을 위한 이진 트리 구성
    Info = info;
    Graph.resize(info.size());
    for (const auto& edge: edges)
    {
        Graph[edge[0]].push_back(edge[1]);
    }

    int answer = 1;
    vector<int> next;
    search(answer, 0, 0, 0, next);
    
    return answer;
}