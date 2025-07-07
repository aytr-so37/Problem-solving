#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<pair<int, int>>v;
    vector<vector<int>>dp(N, vector<int>(N, 1e9));
    // 구간 dp 구현

    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        v.push_back({ a,b });
        dp[i][i] = 0;
    }

    for (int s = 1; s < N; ++s) {// 구간 크기
        for (int i = 0; i + s < N; ++i) {//구간 시작점: i 구간 끝점: i+s

            for (int k = i; k < i + s; ++k){ // 중간에 끊을 지점
                dp[i][i+s] = min(dp[i][i+s], dp[i][k] + dp[k + 1][i + s] + v[i].first * v[k].second * v[i + s].second);
            }
        }
    }
    cout << dp[0][N - 1];

}

