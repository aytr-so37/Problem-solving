#include <iostream>
#include <cmath>
using namespace std;

int ccw(pair<int, int>, pair<int, int>, pair<int, int>);

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    pair<int,int> p1 = { x1,y1 };
    pair<int, int> p2 = { x2,y2 };
    pair<int, int> p3 = { x3,y3 };
    pair<int, int> p4 = { x4,y4 };

    bool result = true; // 안되는 경우만 거르는게 깔끔할 듯

    // p1 - p2 직선 기준 비교
    int t1 = ccw(p1, p2, p3), t2 = ccw(p1, p2, p4);
    int t3 = ccw(p3, p4, p1), t4 = ccw(p3, p4, p2);
    if (t1 * t2 == 1 || t3 * t4 == 1) result = false;
    if (t1 == 0 && t2 == 0) { // 일직선인 경우
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        if (p2 < p3 || p4 < p1) result = false;
    }    
    if (result) cout << 1;
    else cout << 0;
}

// a를 회전 기준이라보고, b를 기준으로 c가 어디쪽에 있나요?
// 1: 반시계 -1: 시계 0: 일직선
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    long long op = 1LL * (b.first - a.first) * (c.second - a.second) - 1LL * (b.second - a.second) * (c.first - a.first);
    if (op > 0) return 1; //반시계
    else if (op < 0) return -1; // 시계
    else return 0;
}


