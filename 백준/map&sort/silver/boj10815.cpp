#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_set<int>v;
    int N;
    cin >> N; // 숫자 개수
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.insert(num);
    }

    int M;
    cin >> M; // 확인할 숫자 개수

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        if (v.find(num) != v.end()) cout << "1 ";
        else cout << "0 ";
    }

}
