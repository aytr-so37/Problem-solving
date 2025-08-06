#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; string S;
    cin >> N >> M >> S;

    int result = 0;
    stack<char>stk;
    for(int i=0;i<M;++i){
        char t = S[i];
        if (t == 'I') {
            if (stk.empty()) {
                stk.push(t);
            }
            else if (!stk.empty() && stk.top() == 'O') {
                stk.push(t);
            }
            else {
                int re= ((stk.size()-1) / 2 - N + 1);
                if (re > 0) result += re;
                while (!stk.empty()) stk.pop();
                stk.push(t);
            }
        }
        else {
            if (!stk.empty() && stk.top() == 'I') {
                stk.push(t);
            }
            else if (stk.empty()) continue;
            else {
                int re = ((stk.size() - 1) / 2 - N + 1);
                if (re > 0) result += re;
                while (!stk.empty()) stk.pop();
            }
        }
       
    }
    if (!stk.empty()) {
        int re = ((stk.size() - 1) / 2 - N + 1);
        if (re > 0) result += re;
    }
    cout << result;
}
