#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int a = 0, b = 0, c = 0;
    int x;
    for (int i = 0; i < N; ++i) {
        cin >> x;

        int temp = max({ a, b, c });
        a += x;
        b += x;
        swap(b, c);
        swap(a, b);
        a = temp;
    }

    int big = a;
    if (b > big) big = b;
    if (c > big) big = c;

    cout << big << "\n";

    return 0;
}
