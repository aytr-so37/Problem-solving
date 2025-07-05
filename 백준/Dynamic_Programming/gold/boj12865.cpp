#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int N, K; cin >> N >> K; //N:물건 수 K: 최대 무게
    vector<int>dp(K + 1, 0);

    for (int i = 0; i < N; ++i) {
        int W, V; cin >> W >> V;
        for (int w = K; w >= W; --w) {
            dp[w] = max(dp[w], dp[w - W] + V);
        }
    }
    cout << dp[K];
}
