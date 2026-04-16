#include <vector>
#include <algorithm>

using namespace std;

extern int excavate(int);

int solution(vector<int> depth, int money) {
    int n = depth.size();
    
    // dp[i][j]: 구간 [i, j]에서 보물을 찾기 위해 '최악의 경우' 감수해야 하는 최소 비용
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // opt[i][j]: 구간 [i, j]일 때 파야 하는 '최적의 인덱스' (정답지)
    vector<vector<int>> opt(n, vector<int>(n, 0));
    
    // 1. 길이를 1부터 n까지 점진적으로 늘려가며 DP 테이블 채우기
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            
            if (i == j) {
                // 구간이 1칸이면 무조건 거기를 파야 함
                dp[i][j] = depth[i];
                opt[i][j] = i;
            } else {
                int min_worst_cost = 2e9; // 무한대 
                int best_k = -1;
                
                // i부터 j까지 중 어디를 파야 '최악의 비용'이 제일 적게 들지 시뮬레이션
                for (int k = i; k <= j; ++k) {
                    // 왼쪽으로 갈 경우와 오른쪽으로 갈 경우 중 더 비용이 큰 쪽(최악)을 채점기가 고를 것임
                    int left_cost = (k == i) ? 0 : dp[i][k - 1];
                    int right_cost = (k == j) ? 0 : dp[k + 1][j];
                    
                    int worst_cost = depth[k] + max(left_cost, right_cost);
                    
                    if (worst_cost < min_worst_cost) {
                        min_worst_cost = worst_cost;
                        best_k = k;
                    }
                }
                
                dp[i][j] = min_worst_cost;
                opt[i][j] = best_k;
            }
        }
    }
    
    // 2. 완성된 정답지(opt)를 보고 굴착 시작
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        // 현재 유효한 구간에서 가장 안전한 최적의 위치를 꺼냄
        int k = opt[left][right];
        
        // excavate는 1-based 인덱스를 받으므로 + 1
        int direction = excavate(k + 1); 
        
        if (direction == 0) {
            return k + 1; // 보물 발견!
        } else if (direction == 1) {
            left = k + 1; // 보물이 더 큰 위치에 있음
        } else if (direction == -1) {
            right = k - 1; // 보물이 더 작은 위치에 있음
        }
    }
    
    return 0;
}