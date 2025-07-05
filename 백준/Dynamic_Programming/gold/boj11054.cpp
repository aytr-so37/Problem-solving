#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int>v(N+2,0);
	vector<int>dp(N + 2, 0);
	vector<int>dp2(N + 2, 0);
	for (int i = 1; i <= N; ++i) {
		int a; cin >> a;
		v[i] = a;
	}// vector setting

	for (int i = 1; i <= N; ++i) {
		int biggest = 0;
		for (int j = i - 1; j >= 0; --j) {	// LIS 구현
			if (v[i] > v[j] && dp[j]>biggest) {
				biggest = dp[j];
			}
		}
		dp[i] = biggest + 1;
	}

	for (int i = N; i >= 1; --i) { // LDS 구현
		int biggest = 0;
		for (int j = i + 1; j <= N + 1; ++j) {
			if (v[i] > v[j] && dp2[j] > biggest) {
				biggest = dp2[j];
			}
		}
		dp2[i] = biggest + 1;
	}

	int big = 0;
	for (int i = 0; i <= N; ++i) { // 꺾이는 부분에서 연산
		if (dp[i] + dp2[i] - 1 > big) big = dp[i] + dp2[i] - 1;
	}

	cout << big;
}
