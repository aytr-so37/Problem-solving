#include <iostream>
#include <vector>
using namespace std;

vector<int>arr, t;
void build(int, int, int);
int m(int, int, int, int, int);
void update(int, int, int, int, int);

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;// 수열의 크기
	arr.resize(N);
	t.resize(4 * N);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		arr[i] = a;
	} // arr setting
	
	build(1, 0, N - 1);
	// segment build

	int M; cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) { // update
			update(1, 0, N - 1, b - 1, c);
			arr[b - 1] = c;
		}
		else if(a == 2) {
			int re = m(1, 0, N - 1, b - 1, c - 1);
			cout << find(arr.begin()+b-1, arr.begin()+c, re) - arr.begin()+1 << "\n";
		}

	}

}

void build(int v, int tl, int tr) { // 최솟값 return
	if (tl == tr) {
		t[v] = arr[tl];
	} // 범위가 1이 되었을 때
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}

int m(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 1e9;
	}
	if (l == tl && r == tr) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return min(m(v * 2, tl, tm, l, min(r, tm)), m(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		t[v] = new_val;
	}
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm) { // 왼쪽 노드로 범위에 있다면
			update(v * 2, tl, tm, pos, new_val);
		}
		else {
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		}
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}
