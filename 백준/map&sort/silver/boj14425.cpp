#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<string>v;
    int N, M;
    cin >> N>>M; //string 개수
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        v.insert(str);
    } //str setting

    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        string str;
        cin >> str;
        if (v.find(str) != v.end()) cnt++;
    }
    cout << cnt << "\n";
}
