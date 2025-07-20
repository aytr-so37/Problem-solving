#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>>graph;
vector<pair<int, int>>zero;
vector<pair<int, int>>st;


int main()
{
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };
    int N, M; cin >> N >> M;
    graph = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int a; cin >> a;
            graph[i][j] = a;
            if (a == 0) zero.push_back({ i,j }); // 0인 곳 vector에 넣기
            if (a == 2) st.push_back({ i,j }); // 2 인 곳 넣기
        }
    } //  graph setting

    int result_max = 0;

    for (int i = 0; i < zero.size() - 2; ++i) {
        for (int j = i + 1; j < zero.size() - 1; ++j) {
            for (int k = j + 1; k < zero.size(); ++k) {
                vector<vector<int>>ngraph = graph;
                int ax = zero[i].first; int ay = zero[i].second;
                int bx = zero[j].first; int by = zero[j].second;
                int cx = zero[k].first; int cy = zero[k].second;
                ngraph[ax][ay] = 1;
                ngraph[bx][by] = 1;
                ngraph[cx][cy] = 1; // 새로운 그래프를 복제하여 벽 3개 세워주기

                // 여기서 부터 bfs
                // 함수 만들기 귀찮으니 여기다가 구현함
                queue<pair<int,int>>bfs;
                for (pair<int,int> a : st) { // 시작점들 bfs에 담기
                    bfs.push(a);
                }

                while (!bfs.empty()) {
                    int x = bfs.front().first;
                    int y = bfs.front().second;
                    bfs.pop();

                    for (int i1 = 0; i1 < 4; ++i1) {
                        int nx = x + dx[i1]; int ny = y + dy[i1];
                        if (0 <= nx && nx < N && 0 <= ny && ny < M) { // 경계 check
                            if (ngraph[nx][ny] == 0) {
                                ngraph[nx][ny] = 1; // 방문하는 곳은 모두 1로 바꿔서 visited 역할
                                bfs.push({ nx,ny });
                            }
                        }
                    }
                }
                // bfs 끝

                int r = 0;
                for (int i1 = 0; i1 < N; ++i1) {
                    for (int i2 = 0; i2 < M; ++i2) {
                        if (ngraph[i1][i2] == 0) r++; // bfs가 끝난 그래프에서 0개수 세기
                    }
                }

                result_max = max(result_max, r); // 최종 결과에 update

            }
        }
    }


    cout << result_max;
}

