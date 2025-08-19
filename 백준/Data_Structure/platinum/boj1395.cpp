#include <iostream>
#include <vector>
using namespace std;

vector<int>t;
vector<bool>lazy;

void update(int, int, int, int, int);
void push(int, int, int);
int query(int, int, int, int, int);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    t.resize(4 * N, 0);
    lazy.resize(4 * N, false);

    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0) { // update
            update(1, 0, N - 1, b - 1, c - 1);
        }
        else if (a == 1) { // query
            cout << query(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}

void update(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);

    if (tr<l || tl>r) return;

    if (l <= tl && tr <= r) { // 뭉텅이 처리 가능
        lazy[v] = !lazy[v];
        push(v, tl, tr);
    }
    else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm));
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v]) { // 반전 시켜야 한다면
        if (tl != tr) {
            lazy[v * 2] = !lazy[v * 2];
            lazy[v * 2 + 1] = !lazy[v * 2 + 1];
        }
        lazy[v] = false; // 반전 시켰음

        t[v] = tr - tl + 1 - t[v]; // 전체 개수 반전
    }
}

int query(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);

    if (r < tl || tr < l) return 0;

    if (l <= tl && tr <= r) return t[v];

    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
        query(v * 2+1, tm + 1, tr, max(tm + 1, l), r);
}
