#include <iostream>
#include <vector>
using namespace std;

using ull = unsigned long long;
vector<ull>tree;
const ull mod = 1000000007;
ull time(ull, ull);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ull N, M, K; cin >> N >> M >> K;
    // N: 수의 개수 M: 변경 횟수 K: 쿼리 개수

    tree.resize(4 * N,1);
    ull size = 1;
    while (size < N) size *= 2;

    for (ull i = 0; i < N; ++i) {
        ull a; cin >> a;
        tree[i + size] = a % mod; // leaf node setting
    }

    for (ull i = tree.size() - 1; i >= 2; --i) {
        tree[i / 2] = (tree[i / 2] * tree[i]) % mod;
    } // full segment tree setting

    for (ull i = 0; i < M + K; ++i) {
        ull a, b, c; cin >> a >> b >> c;
        if (a == 1) { // b번째를 c로 바꾸기 //update
            b += size - 1; // leaf index로 변경
            tree[b] = c;
            b /= 2;
            while (b >= 1) {
                tree[b] = (tree[b * 2] * tree[b * 2 + 1]) % mod;
                b /= 2;
            }
        }
        else if (a == 2) { // b부터 c까지 구간 곱
            cout << time(b + size - 1, c + size - 1) << "\n";
        }
    }

}

ull time(ull start, ull end) {
    if (end < start) return 1;

    if (start % 2 == 1 && end % 2 == 0) {
        return (((tree[start] * tree[end]) % mod) * time((start + 1) / 2, (end - 1) / 2)) % mod;
    }
    else if (start % 2 == 1) {
        return (tree[start] * time((start + 1) / 2, end / 2)) % mod;
    }
    else if (end % 2 == 0) {
        return (tree[end] * time(start / 2, (end - 1) / 2)) % mod;
    }
    else return time(start / 2, end / 2);
}
