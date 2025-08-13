#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    for (int i = 0; i < N - 1; ++i) cout << " ";
    cout << "*\n";// first line

    for (int i = 2; i < N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < (i - 1) * 2 - 1; ++j) {
            cout << " ";
        }
        cout << "*\n";
    }

    if(N!=1)
    for (int i = 0; i < 2 * N - 1; ++i) cout << "*";
}
