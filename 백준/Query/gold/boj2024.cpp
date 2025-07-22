#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
vector<int> tree;

ll sum(ll, ll);Q

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, M, K; cin >> N >> M >> K;
    // N: 수의 개수 M: 수 변경 횟수 K: 쿼리 개수

    tree.resize(4 * N , 0);

    ll size = 1;
    while (size < N) size *= 2; // size = 리프 노드 개수
    // 리프는 tree[size + i]에 저장


    for (ll i = 0; i < N; ++i) {
        ll a; cin >> a;
        tree[i + size] = a;
    } // leaf 노드에 값 가져다 놓기

    for (ll i = tree.size() - 1; i >= 2; --i) {
        tree[i / 2] += tree[i];
    } // tree setting


    for (int i = 0; i < M + K; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1) { // b번째 수 -> c로 update
            b += size-1 ;
            int p = c - tree[b];
            while (b >= 1) {
                tree[b] += p;
                b /= 2;
            }
        }
        else if(a==2) { // b번째부터 c번째까지의 합 출력
            cout << sum(b+size-1, c+size-1) << "\n";
        }
    }
}

ll sum(ll start, ll end) {
    if (end < start) return 0;


    if (start % 2 == 1 && end % 2 == 0) {
        return tree[start] + tree[end] + sum((start + 1) / 2, (end - 1) / 2);
    }
    else if (start % 2 == 1) {
        return tree[start] + sum((start + 1) / 2, end / 2);
    }
    else if (end % 2 == 0) {
        return tree[end] + sum(start / 2, (end - 1) / 2);
    }
    else {
        return sum(start / 2, end / 2);
    }
    
}


