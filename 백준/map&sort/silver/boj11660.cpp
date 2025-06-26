#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

ull prefix_sum(int, int, int, int, const vector<vector<int>>&);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M; // N:표의 크기 M: 합을 구해야 하는 횟수

    vector<vector<int>>graph(N, vector<int>(N+1, 0));
    for (int i = 0; i < N; ++i) {
        int a;
        for (int j = 1; j <= N; ++j) {
            cin >> a;
            graph[i][j] = graph[i][j - 1] + a;
        }
    } // 각 행의 vector를 누적합 형태로 입력해놓기

    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix_sum(x1-1, y1, x2-1, y2, graph) << "\n";
        // 매우 보기 불편하지만 누적합을 사용하는 
        // y는 1 based index로 x는 0 based index를 이용합시다 ㅠㅠ
    }
}

ull prefix_sum(int x1, int y1, int x2, int y2, const vector<vector<int>>& graph) {
    ull result = 0;
    for (int i = x1; i <= x2; ++i) {
        result += graph[i][y2] - graph[i][y1-1];
    }
    return result;
}
