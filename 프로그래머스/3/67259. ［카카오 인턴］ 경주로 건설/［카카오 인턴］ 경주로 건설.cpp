#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node() {}
    Node(int inY, int inX, int inCost, int inDir) : y(inY), x(inX), cost(inCost), dir(inDir) {} 
    
    int y = 0;
    int x = 0;
    int dir = 0;
    int cost = 0;
};

int N;

bool isInRange(const int y, const int x) { return x >= 0 && x < N && y >= 0 && y < N; }

int BFS(vector<vector<int>>& board)
{
    auto queueCmp = [](const Node& a, const Node& b){ return a.cost > b.cost; };
    priority_queue<Node, vector<Node>, decltype(queueCmp)> pq(queueCmp);
    pq.push(Node(0, 0, 0, -1));
    
    vector<vector<int>> visitedCost(N, vector<int>(N, 99999999));
    visitedCost[0][0] = 0; 
    
    const int dy[4] = {0, 0, 1, -1};
    const int dx[4] = {1, -1, 0, 0};
    
    while(!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();
        
        if (curr.x == N-1 && curr.y == N-1) { return curr.cost; }
        
        for (int i=0; i<4; ++i)
        {
            const int nxtDir = i;
            const int ny = curr.y + dy[i];
            const int nx = curr.x + dx[i];

            if (isInRange(ny, nx) == false || board[ny][nx] == 1) { continue; }
            
            int nxtCost = 0;
            if (curr.dir == -1)
            {
                nxtCost = curr.cost + 100;
            }
            else
            {
                nxtCost = (nxtDir == curr.dir) ? curr.cost + 100 : curr.cost + 600;
            }
            
            if (nxtCost <= visitedCost[ny][nx] + 500)
            {
                visitedCost[ny][nx] = min(visitedCost[ny][nx], nxtCost);
                pq.push(Node(ny, nx, nxtCost, nxtDir));
            }
        } 
    }
    
    return 0;
}

int solution(vector<vector<int>> board) 
{
    N = board.size();
    
    return BFS(board);
}