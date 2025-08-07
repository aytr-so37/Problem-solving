#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        int k; cin >> k; // num of cal

        multiset<int>ms;

        for (int j = 0; j < k; ++j) {
            char t; int n; //t: D or I n: 숫자
            cin >> t >> n;

            if (t == 'I') {
                ms.insert(n);
            }
            else { // t=='D'
                if (ms.empty()) continue;
                else if (n == 1) ms.erase(--ms.end());
                else ms.erase(ms.begin());
            }
        }

        if (ms.empty()) cout << "EMPTY\n";
        else {
            cout << *ms.rbegin() << " " << *ms.begin() << "\n";
        }
    }
}
