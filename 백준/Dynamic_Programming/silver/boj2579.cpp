#include <iostream>
#include <vector>
using namespace std;

void bottomup(int, vector<vector<int>>&,const vector<int>&);

int main()
{
    int N;
    cin >> N;
    vector<int>stair;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        stair.push_back(a);
    } // 계단 값들 저장 완

    vector<vector<int>>dp(2, vector<int>(N));
    //최대 값을 2차원 vector로 만들어서
    //바로 전 stair를 밟았으면 1행에
    //아니면 0행에 저장해서 구별하기

    dp[0][0] = stair[0];//시작에서 1번 계단 밟기
    dp[0][1] = stair[1];//시작에서 2번 계단 바로 밟기
    dp[1][1] = stair[0] + stair[1];//시작에서 1번,2번 순으로 밟기

    for (int i = 2; i < N; ++i) {
        bottomup(i, dp,stair);
    }

    cout << max(dp[0][N - 1], dp[1][N - 1]);
}

void bottomup(int a, vector<vector<int>>& dp,const vector<int>& stair) {
    dp[1][a] = dp[0][a - 1] + stair[a];
    // 그 전 계단을 밟고 최대인 경우는
    // 그 전 계단의 전 계단을 안 밝고 최대인 경우 + 내 stair의 점수 ㅋㅋㅋ

    dp[0][a] = max(dp[0][a - 2], dp[1][a - 2]) + stair[a];
    // 그 전 계단을 안 밝고 최대인 경우는
    // 그 전전 계단의 전 계단을 밟든 말든 상관 없으니
    // 둘 중 max인 경우로 ㅎㅎ
}
