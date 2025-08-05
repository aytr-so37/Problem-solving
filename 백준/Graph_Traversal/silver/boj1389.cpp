#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    vector<vector<int>>v(N, vector<int>(N, -1));
    vector<vector<int>>edge(N); // 간선 리스트

    for (int i = 0; i < M; ++i) {
        int s, e; cin >> s >> e;
        edge[s - 1].push_back(e - 1);
        edge[e - 1].push_back(s - 1);
    } // edge set ( 0 based index )

    int min_kevin = 1e9;
    int result = -1;
    for (int i = 0; i < N; ++i) {
        v[i][i] = 0;
        queue<int>bfs;
        bfs.push(i);
        int sum = 0;
        while (!bfs.empty()) {
            int temp = bfs.front();
            bfs.pop();
            for (int a : edge[temp]) {
                if (v[i][a] == -1) {
                    v[i][a] = v[i][temp] + 1;
                    sum += v[i][a];
                    bfs.push(a);
                }
            }
        }
        if (min_kevin > sum) {
            result = i + 1;
            min_kevin = sum;
        }
    }
    cout << result;
}
