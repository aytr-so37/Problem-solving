### Brainstorming


#### 태그
[#Bottom-up DP](#Bottom-up_DP)


#### 오류


#### 완성 코드
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>>graph(3, vector<int>(N, 0));
    //  1: R 2: G 3:B라 하자
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[0][i] = a;
        graph[1][i] = b;
        graph[2][i] = c;
    } // 색들 모두 setting

    vector<vector<int>>shortest(3, vector<int>(N, 0));
    // 각 집을 각 색깔로 칠하는 데 드는 비용의 최솟값
    shortest[0][0] = graph[0][0];
    shortest[1][0] = graph[1][0];
    shortest[2][0] = graph[2][0];

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            shortest[j][i] = graph[j][i] + min(shortest[(j + 1) % 3][i - 1] , shortest[(j + 2) % 3][i - 1]);
        }
    } // i번째 집을 j번째 색으로 칠하는 최소 총비용
      // = i번째 집 j번째 비용 + i-1번집 j번 색이 아닌 집 중에서 더 작은 총비용

    cout << min( min(shortest[0][N - 1], shortest[1][N - 1]), shortest[2][N - 1]);

    return 0;
}
