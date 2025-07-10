#include <iostream>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;

double distance(pair<int, int>, pair<int, int>);
double cal(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);
// 방향 지켜서 넣어주기

int main()
{
    cout << setprecision(10) << fixed;
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if ((y1 - y2) * (x2 - x3) == (y2 - y3) * (x1 - x2)) {
        cout << -1;
        return 0;
    } // 세 점이 한 직선 위에 있을 경우 -1 출력


    pair<int, int>a = { x1,y1 };
    pair<int, int>b = { x2,y2 };
    pair<int, int>c = { x3,y3 };

    double minn = 1e9;
    double maxx = 0;

    pair<int, int>ab = { x1 + x2 - x3,y1 + y2 - y3 };
    double result_ab=cal(a, c, b, ab);
    minn = min(minn, result_ab);
    maxx = max(maxx, result_ab);

    pair<int, int>ac = { x1 + x3 - x2,y1 + y3 - y2 };
    double result_ac = cal(a, b, c, ac);
    minn = min(minn, result_ac);
    maxx = max(maxx, result_ac);

    pair<int, int>bc = { x2 + x3 - x1,y2 + y3 - y1 };
    double result_bc = cal(b, a, c, bc);
    minn = min(minn, result_bc);
    maxx = max(maxx, result_bc);

    cout << maxx - minn;

}

double cal(pair<int, int>a, pair<int, int>b, pair<int, int>c, pair<int, int>d) {
    return distance(a, b) + distance(b, c) + distance(c, d) + distance(d, a);
}

double distance(pair<int, int>x, pair<int, int>y) { // 점 사이의 거리
    double result = sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
    return result;
}
