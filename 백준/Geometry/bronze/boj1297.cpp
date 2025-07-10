#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int D, H, W; cin >> D >> H >> W;
    //D: 대각선 길이 H: 높이 비 W: 너비 비
    double a = sqrt(H * H + W * W);
    // 대각선의 비

    double ww = D / a;
    // 가중치 -> ww*비=실제값

    cout << (int)(ww * H) << " " << (int)(ww * W);
}
