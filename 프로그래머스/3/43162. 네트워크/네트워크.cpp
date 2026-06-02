#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    vector<bool> visited(computers.size(), false);
    for (int i=0; i<computers.size(); ++i)
    {
        queue<int> q;
        q.push(i);
        int tries = 0;
        
        while(q.empty() == false)
        {
            const int curr = q.front();
            q.pop();
            
            if (visited[curr]) { continue; }
            
            visited[curr] = true;
            tries++;
            
            for (int j=0; j<computers[i].size(); ++j)
            {
                if (curr == j) {continue;}
                if (computers[curr][j] == 0) {continue;}
                if (visited[j]) {continue;}
                
                q.push(j);
                tries++;
            }
        }
        
        if (tries >= 1)  { answer++; }
    }
    
    return answer;
}