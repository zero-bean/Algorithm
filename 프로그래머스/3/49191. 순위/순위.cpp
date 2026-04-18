#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> history(n, vector<int>(n, 0));
    int answer = 0;
    
    // history 초기화
    const int size = results.size();
    for (int i=0; i<size; ++i)
    {
        const vector<int> result = results[i];
        history[result[0]-1][result[1]-1] = 1;
        history[result[1]-1][result[0]-1] = -1;
    }
    
    // history 갱신
    for (int mid=0; mid<n; ++mid)
    {
        for (int start=0; start<n; ++start)
        {
            for (int end=0; end<n; ++end)
            {
                if (history[start][mid] == 1 && history[mid][end] == 1)
                {
                    history[start][end] = 1;
                    history[end][start] = -1;
                }
            }
        }
    }
    
    for (int i=0; i<n; ++i)
    {
        int zeroCnt = 0;
        
        for (int j=0; j<n; ++j)
        {
            if (history[i][j] == 0)
            {
                zeroCnt++;
            }
        }
        
        if (zeroCnt == 1)
        {
            answer++;
        }
    }
    
    return answer;
}