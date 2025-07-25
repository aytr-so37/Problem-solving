#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> arr, lt;
void build(int, int, int);
void lazy_update(int, int, int, int, int, int);
ll query(int, int, int, int);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;

    arr.resize(N);
    lt.resize(4 * N);

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        arr[i] = a;
    } // original arr set

    build(1, 0, N - 1);

    int M; cin >> M; 
    // 쿼리 개수
    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        if (a == 1) { // update
            int b, c, d; cin >> b >> c >> d;
            lazy_update(1, 0, N - 1, b - 1, c - 1, d);
        }
        else if (a == 2) {
            int b; cin >> b;
            cout << query(1, 0, N - 1, b - 1) << "\n";
        }
    }

}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        lt[v] = arr[tl];
    } // leaf에만 arr 값
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        lt[v] = 0; // leaf 제외한 곳은 0
    }
}

void lazy_update(int v, int tl, int tr, int l, int r, int val) {
    if (r < tl || tr < l) return;
    if (l<=tl && tr <= r) {
        lt[v] += val;
    }
    else {
        int tm = (tl + tr) / 2;
        lazy_update(v * 2, tl, tm, l, min(tm, r),val);
        lazy_update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r,val);
    }
}

ll query(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return lt[v];
    }

    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        return lt[v] + query(v * 2, tl, tm, pos);
    }
    else {
        return lt[v] + query(v * 2 + 1, tm + 1, tr, pos);
    }
}
