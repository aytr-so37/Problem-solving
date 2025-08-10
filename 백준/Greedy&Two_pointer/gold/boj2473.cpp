#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll N; cin >> N;
	vector<ll>v(N);
	for (ll i = 0; i < N; ++i) {
		ll a; cin >> a;
		v[i] = a;
	}
	sort(v.begin(), v.end());

	ll mn = 3e9; // 최대한 0에 가까운
	ll a=0, b=0, c=0;
	for (ll i = 0; i < N - 2; ++i) {
		ll  m = 3e9;
		ll ta, tb, tc;

		ll left = i + 1;
		ll right = N - 1; // two-pointer

		while (left < right) {
			if (abs(v[i] + v[left] + v[right]) < m) {
				ta = v[i]; tb = v[left]; tc = v[right];
				m = abs(v[i] + v[left] + v[right]);
			}
			if (v[i] + v[left] + v[right] < 0)left++;
			else right--;
		}
		if (mn > m) {
			mn = m;
			a = ta; b = tb; c = tc;
		}
	}

	cout << a << " " << b << " " << c;
}
