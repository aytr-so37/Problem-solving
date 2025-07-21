#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, Q; cin >> N >> M >> Q;
    // N : 도시 개수 M : 도로 개수 Q: 질문의 개수

    vector<vector<pair<int, int>>>v(N, vector<pair<int, int>>(N, { 1e9,0 }));


    vector<pair<int, int>> obs;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        obs.push_back({ i,a });
        v[i][i].first = a;
        v[i][i].second = a; // 자기 자신에게 도착해도 멍멍이의 방해를 받는다
    }// 각 노드에서의 멍멍이의 방해 값
    sort(obs.begin(), obs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });

    for (int i = 0; i < M; ++i) {
        int s, e, w; cin >> s >> e >> w;
        v[s - 1][e - 1].first = w + max(v[s-1][s-1].second, v[e-1][e-1].second);
        v[e - 1][s - 1].first = w + max(v[s - 1][s - 1].second, v[e - 1][e - 1].second);
        v[s - 1][e - 1].second = max(v[s - 1][s - 1].second, v[e - 1][e - 1].second);
        v[e - 1][s - 1].second = max(v[s - 1][s - 1].second, v[e - 1][e - 1].second);
    } // 간선들 초기 setting

    // 질문들은 graph를 모두 setting 한 후에 받도록 하자

    for (int k = 0; k < N; ++k) {
        int n = obs[k].first; // 문제의 위치 -> 왜 적은 순으로 정렬해야할까
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (v[i][n].first != 1e9 && v[n][j].first != 1e9) {
                    if (v[i][n].first + v[n][j].first - min(v[i][n].second, v[n][j].second) < v[i][j].first) { //update가 이뤄져야 한다면
                        v[i][j].first = v[i][n].first + v[n][j].first - min(v[i][n].second, v[n][j].second);
                        v[i][j].second = max(v[i][n].second, v[n][j].second);
                    }
                }
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        int s, e; cin >> s >> e;
        if (v[s - 1][e - 1].first == 1e9) {
            cout << -1 << "\n";
        }
        else {
            cout << v[s - 1][e - 1].first << "\n";
        }
    }
}
