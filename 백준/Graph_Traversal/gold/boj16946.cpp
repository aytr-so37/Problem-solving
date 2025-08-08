#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;
using pii = pair<int, int>;
int N, M;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

vector<vector<int>>v;
bool isValid(int, int);
int bfs(int, int, int);
int num = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    v = vector<vector<int>>(N, vector<int>(M,0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char a; cin >> a;
            if (a == '1') v[i][j] = -1;
            else v[i][j] = -2;
        }
    } // map set

    vector<int> cnt;
    int c = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == -2) { //아직 bfs가 안 돈 ~벽
                cnt.push_back(bfs(i, j, c));
                c++;
            }
        }
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == -1) {
                int sum = 0;
                unordered_set<int>a;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (isValid(nx, ny)&&v[nx][ny]!=-1) {
                        int t = v[nx][ny];
                        if (a.find(t) == a.end()) {
                            a.insert(t);
                            sum += cnt[t];
                        }
                    }
                }
                cout << (sum+1) % 10;
            }
            else cout << "0";    
        }
        cout << "\n";
    }

}

int bfs(int x, int y, int to) {
    queue<pii>q;
    q.push({ x,y });
    v[x][y] = to;
    int num = 1;
    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (isValid(nx, ny) && v[nx][ny] == -2) {
                v[nx][ny] = to;
                q.push({ nx,ny });
                num++;
            }
        }
    }
    return num;
}

bool isValid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}
