#include <iostream>
#include <vector>
using namespace std;

vector<int>arr, t;
vector<int>lazy;

void build(int, int, int);
void push(int, int, int);
void update(int, int, int, int, int, int);
int query(int, int, int, int, int);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    t.resize(4 * N, -1);
    arr.resize(N, -1);
    lazy.resize(4 * N, 0);

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        arr[i] = a;
    } // init set

    build(1, 0, N - 1); // segtree build

    int M; cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            int d; cin >> d;
            update(1, 0, N - 1, b , c,d);
        }
        if (a == 2) {
            cout << query(1, 0, N - 1, b, c) << "\n";
        }
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = arr[tl]; // leaf
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] ^ t[v * 2 + 1]; // xor
}

void push(int v, int tl, int tr) {
    if (lazy[v]!=0) { // push 해야할 xor이 있다면
        if (tl != tr) { // 현재 노드가 leaf가 아니라면
            lazy[v * 2] ^= lazy[v];
            lazy[v * 2 + 1] ^= lazy[v];
        }
        if ((tr - tl + 1) % 2==1) {
            t[v] ^= lazy[v];
        }
        lazy[v] = 0; // lazy push 완료
    }
}

void update(int v, int tl, int tr, int l, int r,int k) {
    push(v, tl, tr);
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        lazy[v] ^= k;
        push(v, tl, tr);
        return;
    }

    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), k);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, k);
    t[v] = t[v * 2] ^ t[v * 2 + 1];
}

int query(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);

    if (tr<l || tl>r) return 0;

    if (l <= tl && tr <= r) {
        return t[v];
    }

    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) ^
        query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
