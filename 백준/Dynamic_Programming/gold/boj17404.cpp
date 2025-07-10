#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<vector<int>>cost(3, vector<int>(N+1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            int a; cin >> a;
            cost[j][i] = a;
            // i번째 집을 j 색으로 칠하는 방법
        }
    }
    cost[0][N] = cost[0][0];
    cost[1][N] = cost[1][0];
    cost[2][N] = cost[2][0];

    int result = 1e9;
    for (int start = 0; start < 3; ++start) {
        // 어디서 시작할까요?
        vector<vector<int>>dp(3, vector<int>(N + 1));
        dp[start][0] = cost[start][0];
        dp[(start + 1) % 3][0] = 1e9;
        dp[(start + 2) % 3][0] = 1e9;
        // 나머지 두 점에선 절대 최소 비용이 나올 수 없도록

        for (int i = 1; i <= N; ++i) {
            for (int k = 0; k < 3; ++k) {
                dp[k][i] = min(dp[(k + 1) % 3][i - 1], dp[(k + 2) % 3][i - 1]) + cost[k][i];
            }
        }
        result = min(result, dp[start][N] - cost[start][0]);
    }

    cout << result;
}

