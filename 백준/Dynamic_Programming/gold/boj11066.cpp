#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	// test case
	vector<vector<int>>dp;
	vector<int>v;

	for (int k = 0; k < T; ++k) {
		int K; // 파일 개수
		cin >> K;
		dp = vector<vector<int>>(K, vector<int>(K, 1e9));
		v = vector<int>(K+1, 1e9);
		for (int i = 0; i < K; ++i) {
			int a; cin >> a;
			dp[i][i] = 0;
			v[i+1] = v[i]+a;//누적합 구현
		}

		for (int size = 2; size <= K; ++size) {
			for (int i = 0; i + size -1 < K; ++i) {
				int end = i + size - 1;
				for (int j = i; j < end; ++j) {
					dp[i][end] = min(dp[i][j] + dp[j+1][end]+v[end+1]-v[i], dp[i][end]);
				}
			}
		}
		cout << dp[0][K-1] << "\n";
	}


}
