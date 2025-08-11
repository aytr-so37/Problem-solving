#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int>v;
vector<vector<bool>>dp;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    v.resize(N);
    dp = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        v[i] = a;
    }

    for (int i = 0; i < N; ++i) dp[i][i] = true;
    for (int i = 0; i < N - 1; ++i) if (v[i] == v[i + 1]) dp[i][i + 1] = true;

    for (int i = 0; i < N; ++i) {
        int left = i - 1; 
        int right = i + 1;
        while (left >= 0 && right < N && v[left] == v[right]) {
            dp[left][right] = true;
            left--;
            right++;
        }
    }

    for (int i = 0; i < N - 1; ++i) {
        if (dp[i][i + 1]) {
            int left = i - 1;
            int right = i + 2;
            while (left >= 0 && right < N && v[left] == v[right]) {
                dp[left][right] = true;
                left--;
                right++;
            }
        }
    }

    int M; cin >> M;
    for(int i=0;i<M;++i){
        int s,e; cin >> s >> e;
        if (dp[s - 1][e - 1]) cout << "1\n";
        else cout << "0\n";
    }
}
