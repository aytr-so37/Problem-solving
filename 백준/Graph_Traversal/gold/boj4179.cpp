#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

void BFS_f(vector<vector<int>>&);
int BFS_j(int, int, vector<vector<int>>&,const vector<vector<int>>&);
bool is_valid(int, int);
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int R, C;
vector<vector<char>>graph;
vector<pair<int, int>>a;

int main()
{
   
    cin >> R >> C; // R: 행 C: 열

    graph=vector<vector<char>>(R, vector<char>(C));
    // graph 

    vector<vector<int>>visited_f(R, vector<int>(C,-1));
    vector<vector<int>>visited_j(R, vector<int>(C,-1));
    //visited check // 불이랑 사람을 따로 관찰

    int j_x=0, j_y=0;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char chr; cin >> chr;
            graph[i][j] = chr;
            if (chr == 'J') {
                j_x = i; j_y = j;
                if (j_x == 0 || j_y == 0 || j_x == R - 1 || j_y == C - 1) {
                    cout << 1 << '\n';
                    return 0;
                }

            }
            if(chr=='F'){
                a.push_back({ i,j });// 불은 여려 개 일 수 있음
            }
        }
    }// graph setting

    BFS_f(visited_f);
    //불이 퍼지는 시간 정리
    int result=BFS_j(j_x, j_y, visited_j, visited_f);
    //사람이 움직일 수 있는 곳, 불보다 빠르게 갈 수 있는 곳만 탐색

    if (result == 1e9) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << result+1;
    }


    
}

void BFS_f(vector<vector<int>>& visited) {
    queue<pair<int, int>>v;
    for (pair<int, int> k : a) {
        v.push({ k.first, k.second });
        visited[k.first][k.second] = 0;
    }
    while (!v.empty()) {
        pair<int, int> t = v.front();
        v.pop();

        for (int i = 0; i < 4; ++i) {
            int new_x = t.first + dx[i];
            int new_y = t.second + dy[i];
            if (is_valid(new_x, new_y) && visited[new_x][new_y] == -1&&graph[new_x][new_y]!='#') {
                v.push({ new_x,new_y });
                visited[new_x][new_y] = visited[t.first][t.second] + 1;
            }
        }
    }
}

int BFS_j(int x, int y, vector<vector<int>>& visited, const vector<vector<int>>&visited2) {
    queue<pair<int, int>>v;
    v.push({ x,y });
    visited[x][y] = 0;
    int shortest = 1e9;
    
    while (!v.empty()) {
        pair<int, int> t = v.front();
        v.pop();

        for (int i = 0; i < 4; ++i) {
            int new_x = t.first + dx[i];
            int new_y = t.second + dy[i];
            if (is_valid(new_x, new_y) && visited[new_x][new_y] == -1&&(visited[t.first][t.second]+1<visited2[new_x][new_y]||visited2[new_x][new_y]==-1) && graph[new_x][new_y] != '#') {
                v.push({ new_x,new_y });
                visited[new_x][new_y] = visited[t.first][t.second] + 1;
                if (new_x == 0 || new_y == 0 || new_x == R-1 || new_y == C-1) {
                    if (visited[new_x][new_y]<shortest) {
                        shortest = visited[new_x][new_y];
                    }
                }

            }
        }
    }
    return shortest;
}

bool is_valid(int a, int b) {
    return (0 <= a && a < R && 0 <= b && b < C);
}

