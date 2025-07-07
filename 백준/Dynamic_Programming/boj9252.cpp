#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string a, b; cin >> a >> b;

    vector<vector<int>>dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[a.size()][b.size()] << "\n";

    string lcs = "";
    if (dp[a.size()][b.size()]) { //역추적
        int i = a.size(); 
        int j = b.size();
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                lcs = a[i - 1] + lcs;
                i--; j--;
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
    }
    cout << lcs;
}
