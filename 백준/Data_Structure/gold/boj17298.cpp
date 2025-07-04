#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N; //탑의 개수

    stack<int>s;
    vector<int>v;
    vector<int>result(N);

    s.push(1e7 + 1);

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        v.push_back(a);
    }
    for (int i = N-1; i >=0; --i) {

        while (s.top() <= v[i]) s.pop();
        result[i] = s.top();
        s.push(v[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << ((result[i] == 1e7 + 1) ? -1 : result[i]) << " ";
    }
}
