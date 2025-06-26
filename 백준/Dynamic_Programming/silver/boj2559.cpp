#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
cin.tie(NULL);
    int N, K;
    cin >> N >> K; //N: 날짜 수 K: 연속 날짜 수

    vector<int>v;
    v.resize(N+1,0);
    for (int i = 1; i <= N; ++i) {
        int input;
        cin >> input;
        v[i] = input + v[i - 1];
    }// prefix sum setting

    int biggest = -1e9;
    for (int i = 1; i <= N - K + 1; ++i) {
        if (v[i + K - 1] - v[i - 1] > biggest) {
            biggest = v[i + K - 1] - v[i - 1];
        }
    }
    cout << biggest << "\n";    
}
