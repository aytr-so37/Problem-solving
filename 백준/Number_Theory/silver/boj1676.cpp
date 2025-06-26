#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> how25(int);

int main()
{
    vector<pair<int, int>>v(501);
    vector<int>res(501);
    res.push_back(0);
    v[0] = { 0,0 };
    for (int i = 1; i <= 500; ++i) {
        pair<int, int> temp = how25(i);
        v[i] = { temp.first + v[i - 1].first,temp.second + v[i - 1].second };
        res[i] = min(v[i].first, v[i].second);
    } // N-1!의 

    int N;
    cin >> N;
    cout << res[N];

}

pair<int, int> how25(int a) {
    // a라는 수에 2가 몇 번, 5가 몇 번 곱해져 있나를 구해서 pair로 return
    pair<int, int>temp = { 0,0 };
    while (a != 0) {
        if (a % 10 == 0) {
            a /= 10;
            temp.first++;
            temp.second++;
        }
        else if (a % 5 == 0) {
            a /= 5;
            temp.second++;
        }
        else if (a % 2 == 0) {
            a /= 2;
            temp.first++;
        }
        else break;
    }
    return temp;
}
