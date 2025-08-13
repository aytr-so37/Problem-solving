#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c, N; cin >> a >> b >> c >> N;
    int result = 0;
    if (N % c == 0 || N % b == 0 || N % a == 0) result = 1;
    if (result == 0) {
        for (int i = N / c; i >= 0; --i) {
            if (result == 1) break;
            int t = N - c * i;
            if (t % b == 0 || t % a == 0) {
                result = 1; break;
            }
            for (int j = t / b; j >= 0; --j) {
                int tt = t - b * j;
                if (tt % a == 0) {
                    result = 1; break;
                }
            }
        }
    }

    cout << result;
}
