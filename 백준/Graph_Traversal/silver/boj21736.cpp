#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int, int);
int N, M;

int main()
{
    cin >> N >> M;
    vector<vector<int>>v(N, vector<int>(M, -1));
    int sx, sy;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char a; cin >> a;
            if (a == 'I') {
                sx = i; sy = j;
                v[i][j] = 0;
            }
            else if (a == 'O') {
                v[i][j] = 0;
            }
            else if (a == 'P') {
                v[i][j] = 1;
            }
            else {
                v[i][j] = -1;
            }
        }
    } // graph set

    //bfs 
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    queue<pair<int, int>>bfs;
    bfs.push({ sx,sy });
    v[sx][sy] = -1;
    int p = 0;
    while (!bfs.empty()) {
        int tx = bfs.front().first;
        int ty = bfs.front().second;
        bfs.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (isValid(nx, ny) && v[nx][ny] != -1) {
                if (v[nx][ny] == 1) p++;
                bfs.push({ nx,ny });
                v[nx][ny] = -1;
                
            }
        }
    }

    if (p) {
        cout << p;
    }
    else {
        cout << "TT";
    }
}

bool isValid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}
