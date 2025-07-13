#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int>v(N + 1, 0);
	vector<int>dp(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		int a; cin >> a;
		v[i] = a;
	}// vector setting

	for (int i = 1; i <= N; ++i) {
		int biggest = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (v[i] > v[j] && dp[j] > biggest) {
				biggest = dp[j];
			}
		}
		dp[i] = biggest + 1;
	}

	int big = 0;
	int idx = 0;
	for (int i = 0; i <= N; ++i) {
		if (dp[i] > big) {
			big = dp[i];
			idx = i; // 최대 값의 index
		}
	}
	cout << big << "\n";

	vector<int>ree;
	while (idx >= 0) {
		if (dp[idx] == big) {
			ree.push_back(v[idx]);
			big--;
		}
		idx--;
	}

	for (int i = ree.size() - 2; i >= 0; --i) {
		cout << ree[i] << " ";
	}
}
