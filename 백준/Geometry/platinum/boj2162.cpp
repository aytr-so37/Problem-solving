#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

bool isIntersect(pair<pii, pii>, pair<pii, pii>);
int ccw(pii, pii, pii);

vector<int>parent; // disjoint
void unite(int, int);
int find(int);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    parent.resize(N);
    for (int i = 0; i < N; ++i) parent[i] = i;

    vector<pair<pii, pii>>v(N);
    for (int i = 0; i < N; ++i) {
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        v[i] = { {a,b},{c,d} };
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (find(i) != find(j) && isIntersect(v[i], v[j])) { // 교차되어있는데 연결 안됨
                unite(i, j);
            }
        }
    }

    sort(parent.begin(), parent.end());
    int total = 1;
    int cnt = 1;
    int mx = 0;
    for (int i = 0; i < N-1; ++i) {
        if (parent[i] == parent[i + 1]) {
            cnt++;
        }
        else {
            mx = max(mx, cnt);
            cnt = 1;
            total++;
        }
    }
    mx = max(mx, cnt);

    cout << total << "\n" << mx;

}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (b > a) {
        parent[b] = a;
    }
    else parent[a] = b;
}

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {

    pii p1 = l1.first;
    pii p2 = l1.second;
    pii p3 = l2.first;
    pii p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {
        // 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }

    return p1p2 <= 0 && p3p4 <= 0;

}

int ccw(pair<int, int>p1, pair<int, int>p2, pair<int, int>p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}
