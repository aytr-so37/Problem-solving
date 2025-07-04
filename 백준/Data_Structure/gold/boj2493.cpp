#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N; //탑의 개수

    stack<pair<int,int>>s;

    s.push({ 100000001,0 });
    // 수신하지 못한 레이저는 0번째 제일 큰 탑에 부딪힌다고 생각하기
    // + 절대로 pop되지 않는 높은 탑 역할
    for (int i = 0; i < N; ++i) {
        int a;  cin >> a;

        while (s.top().first < a) s.pop();
        cout << s.top().second << " ";
        s.push({ a,i + 1 });
    }
}
