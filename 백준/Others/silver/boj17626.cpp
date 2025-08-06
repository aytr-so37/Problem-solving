#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    
    for (int i = 1; i <= 223; ++i) {
        if (i * i == n) {
            cout << 1;
            return 0;
        }
    }

    for (int i = 1; i <= 223; ++i) {
        for (int j = i; j <= 223; ++j) {
            if (i * i + j * j == n) {
                cout << 2;
                return 0;
            }
        }
    }

    for (int i = 1; i <= 223; ++i) {
        for (int j = 1; j <= 223; ++j) {
            for (int k = 1; k <= 223; ++k) {
                if (i * i + j * j + k * k == n) {
                    cout << 3;
                    return 0;
                }
            }
        }
    }

    cout << 4;
}
