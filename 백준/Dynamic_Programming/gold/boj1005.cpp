#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T; 
    // test case 개수


    for (int t = 0; t < T; ++t) {
        int a, b;  cin >> a >> b;
        // a: 정점 개수 b: 간선 개수
        vector<int>depth(a, -1);
        vector<int>cost(a, -1);
        vector<vector<int>>edges(a);
        vector<vector<int>>need(a);
        vector<int>dp(a, -1);

        for (int i = 0; i < a; ++i) {
            int ip; cin >> ip; 
            cost[i] = ip;
        } //cost setting

        for (int i = 0; i < b; ++i) {
            int from, to; cin >> from >> to; 
            edges[from-1].push_back(to-1);
            need[to - 1].push_back(from - 1);
        } // edges setting

        int goal; cin >> goal; // 지어야할 건물

        queue<int>bfs;
        for (int i = 0; i < a; ++i) {
            if (need[i].empty()) {
                bfs.push(i);
                depth[i] = 1;
            }//전제 노드가 필요없는 노드에서 bfs 시작
        }

        int max = 0; // 최대 depth를 return
        while (!bfs.empty()) { //visited 없이 bfs 구현하자
            int temp = bfs.front();
            bfs.pop();
            for (int i : edges[temp]) {
                int cand = depth[temp] + 1;
                if (cand > depth[i]) {
                    depth[i] = cand;
                    bfs.push(i);
                    if (cand > max)max = depth[i];
                }
            }
        }

        for (int i = 0; i < a; ++i) {
            if (depth[i] == 1) {
                dp[i] = cost[i];
            }
        }
        for (int i = 2; i <= max; ++i) { // depth 작은 순부터 dp채워넣기
            for (int j = 0; j < a; ++j) {
                if (depth[j] == i) {
                    int maxx = 0;
                    for (int ap : need[j]) {
                        if (dp[ap] > maxx) maxx = dp[ap];
                    }
                    dp[j] = maxx + cost[j];
                }
            }

        }
        cout << dp[goal - 1] << "\n";
    }
}

