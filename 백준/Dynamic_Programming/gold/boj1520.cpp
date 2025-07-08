#include <iostream>
#include <vector>
using namespace std;
int M, N;

int DFS(int,int,vector<vector<int>>&);
bool isValid(int, int);//경계 check
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0,1,0,-1 };
vector<vector<int>>v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;

    v=vector<vector<int>>(M, vector<int>(N, -1));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int a; cin >> a;
            v[i][j] = a;
        }
    } // graph setting

    vector<vector<int>>dp(M, vector<int>(N, 0));
    //[i][j]에서 도착지까지 가는 경우의 수를 저장
    // 메모이제이션
    // + 시작점에서 dfs로 이어지는 부분만 update함

    DFS(0,0,dp);

    cout << ((dp[0][0] == -1) ? 0 : dp[0][0]);
    
}

int DFS(int x,int y,vector<vector<int>>& dp) {
    if (x == M - 1 && y == N - 1) {//도착점
        dp[x][y] = 1;
        return 1;
    }

    if (dp[x][y] != 0) return dp[x][y];

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        
        if (isValid(nx, ny) && v[nx][ny] < v[x][y] && dp[nx][ny]!=-1) {
            dp[x][y] += DFS(nx, ny, dp);
        }
    }
    if (dp[x][y] == 0) {// x,y에선 종점에 도착할 수 없음을 시사
        dp[x][y] = -1; // 다시는 시도조차 안하도록
        return 0; // 그래도 더하는 값을 0으로
    }
    return dp[x][y];
}

bool isValid(int x, int y) {
    return (0 <= x) && x < M && 0 <= y && (y < N);
}
