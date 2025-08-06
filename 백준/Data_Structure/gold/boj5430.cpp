#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        string  p; cin >> p;
        // 명령
        deque<int>dq; 
        int n; cin >> n;
        char t1; cin >> t1;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            cin >> t1;
            dq.push_back(a);
        } //set
        if (n == 0) cin >> t1;

        bool err = false;
        bool reverse = false;
        for (int i = 0; i < p.size(); ++i) {
            char t = p[i];
            if (t == 'R') {
                reverse = !reverse;
            }
            else { // D
                if (dq.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                }
                else if (reverse) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (err) continue;
        else {
            cout << "[";
            if (reverse) {
                while (!dq.empty()) {
                    cout << dq.back();
                    if (dq.size() != 1) cout << ",";
                    dq.pop_back();
                }
            }
            else {
                while (!dq.empty()) {
                    cout << dq.front();
                    if (dq.size() != 1) cout << ",";
                    dq.pop_front();
                }
            }
            cout << "]\n";
        }
    }
}
