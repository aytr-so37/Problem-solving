#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int popcount(int x) { //1인 비트 수 세기
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int main()
{
    int N; cin >> N; // 발전소 개수
    vector<vector<int>>cost(N, vector<int>(N, -1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int input; cin >> input;
            cost[i][j] = input;
        }
    } // i to j cost setting

    int status = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        char chr; cin >> chr;
        if (chr == 'Y') {
            status |= (1 << i);
            cnt++;
        } 
    }// status에 초기 상태 저장

    int P; cin >> P; //목표 개수
    if (cnt >= P) {
        cout << "0";
        return 0;
    } // 이미 완성된 경우
    if (cnt == 0) {
        cout << "-1";
        return 0;
    } // 완성될 수 없는 경우

    vector<int>dp(1 << N, 1e9); // N이 30이하이므로 안전
    // dp[불이 켜져있는 상태]=이 상태에 대한 최소비용

    dp[status] = 0;

    int result = 1e9; // 최종 결과
    for (int s = 0; s < (1 << N); ++s) {
        int cnt_on = popcount(s);//현재 상태
        if (dp[s] == 1e9) continue; // 아직 안 채워진 상태
        if (cnt_on >= P) continue; // 이런 case 찾는게 아님 필요도 없고, 같은 경우는 나중에 서서히 찾아짐

        for (int i = 0; i < N; ++i) {
            if (s & (1 << i)) continue; //'Y'인 곳 넘어가기

            int next_cost = 1e9;
            for (int j = 0; j < N; ++j) {
                if (s & (1 << j)) {
                    next_cost = min(next_cost, cost[j][i]);
                    // 'Y'인 곳들 중에서 값을 적게 들이고 키기               
                }
            }
            int next_state = s | (1 << i);
            dp[next_state] = min(dp[next_state], dp[s] + next_cost);
            // 다른 상태에서 더 빨리 왔을 수도 있기 때문에
            if (cnt_on == P-1 && dp[next_state]<result) {
                result = dp[next_state];
            }
            
        }
    }
    cout << result;
}
