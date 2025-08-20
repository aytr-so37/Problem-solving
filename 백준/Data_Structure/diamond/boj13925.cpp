#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;


ll mod = 1e9 + 7; // mod
vector<ll> arr, t;
vector<pll>lazy;

void build(ll, ll, ll);
void update(ll, ll, ll, ll, ll, ll, ll);
void push(ll, ll, ll);
ll query(ll, ll, ll, ll, ll);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N; cin >> N;
    arr.resize(N);
    t.resize(4 * N, 0);
    lazy.resize(4 * N, { 1,0 });

    for (ll i = 0; i < N; ++i) {
        ll a; cin >> a;
        arr[i] = a;
    } // init setting

    build(1, 0, N - 1);

    ll M; cin >> M;
    for (ll i = 0; i < M; ++i) {
        ll a; cin >> a;

        if (a == 4) {
            ll b, c; cin >> b >> c;
            cout << query(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
        else { 
            // a==1 -> +v (1,v)
            // a==2 -> *v (v,0)
            // a==3 -> =v (0,v)
            ll b, c, d; cin >> b >> c >> d;

            update(1, 0, N - 1, b - 1, c - 1, a, d);
        } // a : query 종류 d: v
    }
}

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = arr[tl]%mod;
        return;
    }
    ll tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
}

void push(ll v, ll tl, ll tr) {
    if (lazy[v].first != 1 || lazy[v].second != 0) {
        if (tl != tr) { //not leaf
            lazy[v * 2].first = (lazy[v * 2].first*lazy[v].first) % mod;
            lazy[v * 2].second = (lazy[v * 2].second*lazy[v].first) %mod;
            lazy[v * 2].second= (lazy[v * 2].second+lazy[v].second)%mod; // 왼
            lazy[v * 2 + 1].first =(lazy[v * 2+1].first * lazy[v].first)%mod;
            lazy[v * 2 + 1].second =(lazy[v * 2+1].second * lazy[v].first)%mod;
            lazy[v * 2 + 1].second = (lazy[v * 2+1].second+lazy[v].second)%mod; // 오른
        }
        t[v] = ((lazy[v].first * t[v])%mod + (lazy[v].second * (tr-tl+1))%mod)%mod;
        lazy[v] = { 1,0 }; // 초기화
    }
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll a, ll k) {
    // a==1 -> +v (1,v)
    // a==2 -> *v (v,0)
    // a==3 -> =v (0,v)
    push(v, tl, tr);

    if (tr<l || tl>r) return;

    if (l <= tl && tr <= r) {
        if (a == 1) { 
            lazy[v].second = (lazy[v].second + k) % mod;
        }
        if (a == 2) {
            lazy[v].first = (lazy[v].first * k) % mod;
            lazy[v].second = (lazy[v].second * k) % mod;
        }
        if (a == 3) {
            lazy[v] = { 0,k };
        }
        push(v, tl, tr);
        return;
    }

    ll tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), a, k);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, a, k);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    push(v, tl, tr);
    if (tr<l || tl>r) return 0;
    if (l <= tl && tr <= r) return t[v];

    ll tm = (tl + tr) / 2;
    ll a = query(v * 2, tl, tm, l, min(r, tm));
    ll b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return (a + b) % mod;
}
