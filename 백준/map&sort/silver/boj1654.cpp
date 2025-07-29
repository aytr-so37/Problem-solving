#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

vector<ull>v;

ull result(ull);
ull binary(ull, ull, ull);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ull K, N; cin >> K >> N;
    //K; 랜선의 개수  N: 만들어야 하는 랜선의 개수
    v.resize(K);
    for (ull i = 0; i < K; ++i) {
        ull a; cin >> a;
        v[i] = a;
    }

    ull size = 1;
    while (result(size) >= N) size *= 2;
    // 2의 제곱으로 스케일 잡기

    cout << binary(size / 2, size, N); // 이 사이에 답이 있다


}

ull binary(ull l, ull r,ull flag) {
    ull tl = l;
    ull tr = r;
    while (tl < tr) {
        ull tm = (tl + tr) / 2;
        if (result(tm) >= flag) {
            tl = tm + 1;
        }
        else {
            tr = tm;
        }
    }
    return tl-1;
}

ull result(ull len) {
    ull sum = 0;
    for (ull i = 0; i < v.size(); ++i) {
        sum += (v[i] / len);
    }
    return sum;
}

