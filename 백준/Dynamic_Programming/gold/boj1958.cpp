#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    vector<vector<vector<int>>>dp(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1, 0)));
    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            for (int k = 1; k <= c.size(); ++k) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max(max(dp[i - 1][j][k],dp[i][j - 1][k]),dp[i][j][k - 1]);
                }
            }
        }
    }
    cout << dp[a.size()][b.size()][c.size()];
}
