#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    //N:학생 수  M: 키 비교 횟수
    vector<int>depth(N, 0);
    vector<vector<int>>v(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        v[a-1].push_back(b-1);
        depth[b-1]++;
    }

    priority_queue<int,vector<int>,greater<int>>bfs;
    for (int i = 0; i < N; ++i) {
        if (depth[i] == 0) {
            bfs.push(i);
        }
    } // 0 인 점들 집어 넣기
    while(!bfs.empty()) {
        int temp = bfs.top();
        cout << temp+1 << " ";
        bfs.pop();

        for (int c : v[temp]) {
            depth[c]--;
            if (depth[c] == 0) {
                bfs.push(c);
            }
        }
    }
}
