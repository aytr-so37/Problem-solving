#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct p{
    int x, y, s;
};

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool isValid(int, int);// 경계 check
vector<vector<int>>v;
vector<vector<vector<int>>>visited;
queue<p>bfs;

void bfs_impl();

int main()
{
    cin >> N >> M;
    v = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for(int j=0;j<M;++j){
            char ch; cin >> ch;
            v[i][j] = ch - '0';
        }
    }//graph setting

    visited=vector<vector<vector<int>>>(N,
        vector<vector<int>>(M,
            vector<int>(2,-1)
        )
    ); //최단 거리 but 3차원으로
    // 0층은 벽을 안부수고 최단거리
    // 1층은 벽을 부수고 최단거리

    bfs_impl();
    if (visited[N - 1][M - 1][0] == -1 && visited[N - 1][M - 1][1] == -1) {
        cout << -1;
    }
    else if(min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1])==-1) {
        cout << max(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1])+1;
    }
    else {
        cout << min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1])+1;
    }
    
}

bool isValid(int a, int b) { // 경계 check
    return (0 <= a) && (a < N) && (0 <= b) && (b < M);
} 

void bfs_impl() {
    visited[0][0][0] = 0;
    bfs.push({ 0,0,0 });
    while (!bfs.empty()) {
        int x = bfs.front().x;
        int y = bfs.front().y;
        int s = bfs.front().s; // state
        int now = visited[x][y][s];
        bfs.pop();

        if (s == 1) { //이미 벽뚫을 쓴 분기인 경우
            for (int i = 0; i < 4; ++i) {
                if (isValid(x + dx[i], y + dy[i]) && v[x+dx[i]][y+dy[i]]==0) {
                    if (visited[x + dx[i]][y + dy[i]][1] == -1) {
                        visited[x + dx[i]][y + dy[i]][1] = now + 1;
                        bfs.push({ x + dx[i],y + dy[i],1 });
                    }
                    else if (visited[x + dx[i]][y + dy[i]][1] > now + 1) { // update 되는 경우에만
                        bfs.push({ x + dx[i],y + dy[i],1 });
                        visited[x + dx[i]][y + dy[i]][1] = now + 1;
                    }
                }
            }
        }
        else { // 아직 벽뚫 안 씀
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i]; int ny = y + dy[i];
                if (isValid(nx, ny)) {
                    if (v[nx][ny] == 0 && visited[nx][ny][0]==-1) { // 길이 있는 경우
                        visited[nx][ny][0] = now + 1;
                        bfs.push({ nx,ny,0 });
                    }
                    else if (v[nx][ny] == 1) { // 벽이 있는 경우
                        if (visited[nx][ny][1] == -1) {
                            visited[nx][ny][1] = now + 1;
                            bfs.push({ nx,ny,1 });
                        }
                        else if (visited[nx][ny][1] > now + 1) {
                            visited[nx][ny][1] = now + 1;
                            bfs.push({ nx,ny,1 });
                        }
                    }
                }
            }

        }


    }
}
