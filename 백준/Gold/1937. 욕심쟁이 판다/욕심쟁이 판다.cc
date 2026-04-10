#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node(const pair<int, int>& inPos, const int inAmount) : pos(inPos), amount(inAmount) {}

    bool operator< (const Node& other) const { return amount < other.amount; }

    pair<int, int> pos{ 0, 0 };
    int amount = 0;
};

priority_queue<Node> Orders{};
vector<vector<int>> Board{};
vector<vector<int>> History{};
int N = 0;

inline bool IsInRange(const int y, const int x) { return y >= 0 && y < N && x >= 0 && x < N; }

int DFS(const pair<int, int>& start, int& answer)
{
    if (History[start.first][start.second] != 0)
    {
        return History[start.first][start.second];
    }

    History[start.first][start.second] = 1;
    const int dy[4] = { 0, 0, 1, -1 };
    const int dx[4] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; ++i)
    {
        const int ny = dy[i] + start.first;
        const int nx = dx[i] + start.second;

        if (IsInRange(ny, nx) == false)
        {
            continue;
        }

        // 갱신 시도
        if (Board[start.first][start.second] > Board[ny][nx])
        {
            History[start.first][start.second] = max(History[start.first][start.second], DFS({ ny, nx }, answer) + 1);
            answer = max(answer, History[start.first][start.second]);
        }
    }

    return History[start.first][start.second];
}

int Solve()
{
    int answer = 1;

    while (!Orders.empty())
    {
        const Node curr = Orders.top();
        Orders.pop();
        if (History[curr.pos.first][curr.pos.second] == 0)
        {
            DFS(curr.pos, answer);
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    History.resize(N, vector<int>(N, 0));
    Board.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
            Orders.push(Node({ i, j }, Board[i][j]));
        }
    }

    cout << Solve();

    return 0;
}