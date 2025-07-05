#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N; //전깃줄 개수

    vector<pair<int, int>>v;
    v.push_back({ 0,0 }); //sentry 값
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first < b.first);
        }); // 첫 타워 기준 오름차순

    vector<int>dp(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int biggest = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (v[i].first > v[j].first && v[i].second > v[j].second && dp[j] > biggest) {
                biggest = dp[j];
            }
        }
        dp[i] = biggest+1;
    }

    int big = 0;
    for (int i = 1; i <= N; ++i) {
        if (dp[i] > big) big = dp[i];
    }
    cout << N-big;


}
