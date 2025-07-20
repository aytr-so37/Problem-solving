#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N;
vector<vector<int>>v1; // 일반
vector<vector<int>>v2; // 적록색맹 용

void BFS_impl(int,int,int, vector<vector<int>>&);
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
    cin >> N;
    v1 = vector<vector<int>>(N, vector<int>(N));
    v2 = vector<vector<int>>(N, vector<int>(N)); // resize

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char a; cin >> a;
            if (a == 'R') {
                v1[i][j] = 0; v2[i][j] = 0;
            }
            else if (a == 'B') {
                v1[i][j] = 1; v2[i][j] = 1;
            }
            else { // G 왜 내가 이 순서로 했을까? ㅋㅋ
                v1[i][j] = 2; v2[i][j] = 0;
            }
        }
    } // 그래프 끝

    // 여기부터 구역 수 세기
    int v1_cnt = 0; int v2_cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v1[i][j] != -1) {
                v1_cnt++;
                BFS_impl(v1[i][j],i,j,v1);
            }
            if (v2[i][j] != -1) {
                v2_cnt++;
                BFS_impl(v2[i][j],i,j,v2);
            }
        }
    }
    cout << v1_cnt << " " << v2_cnt;
}

void BFS_impl(int a,int x,int y,vector<vector<int>>& graph) { // a로 이어져 있는 영역 모두 -1로 바꾸기
    queue<pair<int, int>>q;
    q.push({ x,y });
    v1[x][y] = -1;

    while (!q.empty()){

        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = tx + dx[i]; int ny = ty + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N && graph[nx][ny]==a) {
                graph[nx][ny] = -1;
                q.push({ nx,ny });
            }
        }
    }
}
