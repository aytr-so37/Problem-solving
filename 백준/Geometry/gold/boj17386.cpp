#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;


    int result = 0;

    if (x3 == x4) { // y축에 평행한 직선일 경우
        if ((x1-x3)*(x2-x3)<0)result++;  
    }
    else {
        double slope = (y3 - y4) / (x3 - x4); // 다른 직선을 기준으로 하자

        double v_x1 = slope * (x1 - x3) + y3;
        double v_x2 = slope * (x2 - x3) + y3;
        if ((v_x1-y1)*(v_x2-y2)<0) result++;
    }

    if (x1 == x2) {
        if ((x3-x1)*(x4-x1)<0)result++;
    }
    else { // 나머지 경우들
        double slope = (y1 - y2) / (x1 - x2);

        double v_x3 = slope * (x3 - x1) + y1; // 직선에서의 x3에서의 값
        double v_x4 = slope * (x4 - x1) + y1;

        if ((v_x3-y3)*(v_x4-y4)<0) result++;
    }

    if (result == 2) cout << 1;
    else cout << 0;
    
    
}
