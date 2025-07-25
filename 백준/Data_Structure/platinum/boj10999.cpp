#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> arr, t, lazy;
void build(ll, ll, ll);
void push(ll, ll, ll);
void update(ll, ll, ll, ll, ll, ll);
ll sum(ll, ll, ll, ll, ll);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll N, M, K; cin >> N >> M >> K;
	// N: 수의 개수 K: update 개수 M: 쿼리 개수
	arr.resize(N);
	t.resize(4 * N);
	lazy.resize(4 * N, 0);

	for (ll i = 0; i < N; ++i) {
		ll a; cin >> a;
		arr[i] = a;
	} // array setting

	build(1, 0, N - 1); // segment build function call

	for (ll i = 0; i < M + K; ++i) {
		ll a; cin >> a;
		if (a == 1) { // update
			ll b, c, d; cin >> b >> c >> d;
			update(1, 0, N - 1, b - 1, c - 1, d);
		}
		else if (a == 2) { // sum
			ll b, c; cin >> b >> c;
			cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
}

void build(ll v, ll tl, ll tr) {
	if (tl == tr) { // build 하려는 구간 길이가 1이 되었을 때
		t[v] = arr[tl];
	}
	else {
		ll tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	} // 구간 합 segment setting
}

// lazy 배열에 남은 업데이트가 있다면 실제 반영
void push(ll v, ll tl, ll tr) {
	if (lazy[v] != 0) { // 그 vertex에 남은 lazy가 있다면
		t[v] += (tr - tl + 1) * lazy[v];
		if (tl != tr) {
			lazy[v * 2] += lazy[v];
			lazy[v * 2 + 1] += lazy[v];
		}
		lazy[v] = 0;
	} // 해당 lazy 한 단계 아래로 밀어주기
}

// 구간에 val 더하고 lazy에도 더해주기
void update(ll v, ll tl, ll tr, ll l, ll r, ll val) {
	push(v, tl, tr);

	if (l > r || r < tl || tr < l) return;
	//자르고 남은 범위가 구하는 범위에 필요 없음

	if (l <= tl && tr <= r) {
		lazy[v] += val;
		push(v, tl, tr); // 여기에 들어가서 트리엔 적용됨
	}
	else {
		ll tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm), val);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

ll sum(ll v, ll tl, ll tr, ll l, ll r) {
	push(v, tl, tr); // lazy 처리

	if (l > r || r < tl || tr < l) return 0;

	if (l <= tl && tr <= r) return t[v];

	ll tm = (tl + tr) / 2;
	return sum(v * 2, tl, tm, l, min(r, tm)) +
		sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

