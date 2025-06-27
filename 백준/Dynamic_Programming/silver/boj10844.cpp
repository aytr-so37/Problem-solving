#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    int N;    cin >> N;
    // N 자릿수 쉬운 계단 수
    int mod = 1000000000;

    vector<vector<ll>>dp(10,vector<ll>(N));
    dp[0][0] = 0;
    for (int i = 1; i < 10; ++i) {
        dp[i][0]=1;
    } // 한 자리일 때 setting

    for (int i = 1; i < N; ++i) {
        dp[0][i] = dp[1][i - 1];
        for (int j = 1; j < 9; ++j) {
            dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % mod;
        }
        dp[9][i] = dp[8][i - 1];
    }

    ll result = 0;
    for (int i = 0; i < 10; ++i) {
        result += dp[i][N - 1];
    }
    cout << result % mod;

}
