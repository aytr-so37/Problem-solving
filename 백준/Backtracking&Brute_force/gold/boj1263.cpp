#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<pii>v(N);

    int mx = 1e9; 
    int mdeadline = 0;

    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        v[i] = { a,b };
        mx = min(mx, b - a);
        mdeadline = max(mdeadline, b);
    }// Ti, Si set

    sort(v.begin(), v.end(), [](const pii& a, const pii& b) {
        return (a.second < b.second);
        }); // Si가 빠른 순으로 정렬

    for (int i = mx; i >=0; --i) {// i: 시작 시간
        int idx = i; // 시작점 + 현재까지 채워진 시간
        int check = false; // 이번 시도에 통과했나
        for (int j = 0; j < N; ++j) {
            if (idx + v[j].first <= v[j].second) {
                idx += v[j].first;
                if (j == N - 1) check = true; // 다 통과함
            }
            else {
                break; // 이번 idx에선 실패
            }
        }
        if (check) { // 이번 시도에서 성공했다면
            cout << i;
            return 0; // 그냥 프로그램 종료
        }
    }

    cout << -1;

}
