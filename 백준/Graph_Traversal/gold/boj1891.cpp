#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    int d; //string 길이 == graph 슬라이싱 횟수
    string input; // 시작 좌표
    ll x, y; // 제일 낮은 레벨에서 이동 방법
    cin >> d >> input >> x >> y;

    ll s_x = 0, s_y = 0;
    ll max = 1LL << d;

    for (int i = d - 1; i >= 0; --i) {
        char chr = input[d - 1 - i]; // 받은 string의 앞부터 참조
        ll a = 1LL << i; // pow 비트 연산자로 구현


        if (chr == '1') { //행 -> x 열 -> y로 생각하고 구현 함
            s_y += a;
        }
        if (chr == '2') { //안 써도 되지만 이해하기 쉽게 :)
            continue;
        }
        if (chr == '3') {
            s_x += a;
        }
        if (chr == '4') {
            s_x += a;
            s_y += a;
        }
    }

    // string으로 주어진 좌표를
    // [2^d, 2^d] 짜리 vector에서의 index처럼 표현해줌

    ll e_x = s_x - y;
    ll e_y = s_y + x;
    // 문제에선 수학에서 보통 쓰는 x,y로 했는데
    // 행 -> x 열 -> y로 생각하고 구현 함 (참고)

    if (e_x < 0 || e_y < 0||e_x>=max||e_y>=max) {
        cout << -1;
        return 0;
    } 
    // 존재하지 않는 좌표일 때

    for (int i = d-1; i >=0; --i) {
        int xx = e_x % 2;
        int yy = e_y % 2;

        if (xx == 0 && yy == 1) input[i] = '1';
        if (xx == 0 && yy == 0)input[i] = '2';
        if (xx == 1 && yy == 0)input[i] = '3';
        if (xx == 1 && yy == 1)input[i] = '4';

        e_x /= 2;
        e_y /= 2;
        // 로직을 잘 생각해보자!
    }

    cout << input << "\n";
}
