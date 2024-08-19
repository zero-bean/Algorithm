#include <iostream>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

int n;
int num[MAX_NUM][MAX_NUM];
int dp[MAX_NUM][MAX_NUM];

void Initialize() {
    // 시작점의 경우 dp[0][0] = num[0][0]으로 초기값을 설정해줍니다
    dp[0][0] = num[0][0];

    // 최좌측 열의 초기값을 설정해줍니다.
    for(int i = 1; i < n; i++)
        dp[i][0] = min(dp[i-1][0], num[i][0]);

    // 최상단 행의 초기값을 설정해줍니다.
    for(int j = 1; j < n; j++)
        dp[0][j] = min(dp[0][j-1], num[0][j]);
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> num[i][j];

    // 초기값 설정
    Initialize();

    // 탐색하는 위치의 위에 값과 좌측 값 중에 큰 값과
    // 해당 위치의 숫자 중에 최솟값을 구해줍니다.
    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            dp[i][j] = min(max(dp[i-1][j], dp[i][j-1]), num[i][j]);


    cout << dp[n-1][n-1];

    return 0;
}