#include <iostream>
using namespace std;

int main()
{
    int x, n; cin >> x >> n;
    int cnt = 0;
    while (cnt < n) {
        if (x % 2 == 0) {
            x = (x / 2) ^ 6;
        }
        else {
            x = (2 * x) ^ 6;
        }
        cnt++;
    }
    cout << x;
}
