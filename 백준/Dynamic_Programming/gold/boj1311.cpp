#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N; cin >> N; // 사람, 일 수

    vector<vector<int>>cost(N, vector<int>(N, -1));
    for(int i=0;i<N;++i){ //i번째 사람이
        for (int j = 0; j < N; ++j) { // j번째 일을 하는
            int a; cin >> a;
            cost[i][j] = a;
        }
    } // cost setting

    vector<vector<int>>dp(N, vector<int>(1 << N, 1e9));
    //dp[N번째 일까지][일꾼 state]

    queue<pair<int,int>>v;

    for (int i = 0; i < N; ++i) {
        dp[0][1 << i] = cost[i][0];
        v.push({ 0,1 << i });
    } // 0번째 일을 

    //bfs로 구현
    while (!v.empty()) {
        int last = v.front().first; // 이미 완료된 일 단계
        int state = v.front().second; // 소모된 일꾼 state
        v.pop();

        for (int i = 0; i < N; ++i) {
            if (!(state & (1 << i))) { // 안 쓰인 일꾼을 찾아서
                if (dp[last + 1][state | (1 << i)] > dp[last][state]+cost[i][last+1]) {
                    dp[last + 1][state | (1 << i)] = dp[last][state] + cost[i][last + 1];
                    if(last+1!=N-1) v.push({ last + 1,state | (1 << i) });
                }
            }
        }
    }
    
    cout << dp[N - 1][(1 << N) - 1];


}
