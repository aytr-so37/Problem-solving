#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int, vector<vector<int>>&, const vector<vector<int>>&);
int N;

int main() {
    cin >> N;
    vector<vector<int>> cost(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> cost[i][j];

    int min_cost = 1e9;
    for (int start = 0; start < N; ++start) {
        vector<vector<int>> dp(N, vector<int>((1 << N)+1, 1e9));
        int result = BFS(start, dp, cost);
        min_cost = min(min_cost, result);
    }

    cout << min_cost << '\n';
    return 0;
}

int BFS(int s, vector<vector<int>>& dp, const vector<vector<int>>& cost) {
    int result = 1e9;
    dp[s][1 << s] = 0;
    queue<pair<int,int>> v;
    v.push({ s,1 << s });

    while (!v.empty()) {
        int last = v.front().first;
        int state = v.front().second;       
        v.pop();

        for (int to = 0; to < N; ++to) { // 다음에 어디로 갈건데 (to)
            if (state & (1 << to)) continue; // 이미 방문한 도시 skip
            if (dp[last][state] == 1e9) continue;
       
            if (cost[last][to] == 0) continue; // 연결 안 된 경우 skip

            int next_state = state | (1 << to);
            if (dp[to][next_state] > dp[last][state] + cost[last][to]) {
                dp[to][next_state] = dp[last][state] + cost[last][to];
                v.push({ to,next_state });
            }
        }
    }

    int full = (1 << N)-1;
    for (int i = 0; i < N; ++i) {
        if (dp[i][full] == 1e9) continue;
        if (i == s) continue;
        if (cost[i][s] == 0) continue;

        result = min(result, dp[i][full] + cost[i][s]);
    }
    return result;
        
}
