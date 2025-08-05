#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        vector<string>names; // 종류 이름들
        unordered_map<string, int>m;
        
        int n; cin >> n;
        for (int j = 0; j < n; ++j) {
            string a, b; cin >> a >> b; // b만 쓸거임
            if (m.find(b) != m.end()) { // 전에도 있던 종류면
                m[b]++;
            }
            else { // 새로운 종류면
                m[b] = 1;
                names.push_back(b);
            }
        }

        int times = 1;
        for (string s:names) {
            times *= (m[s] + 1);
        }
        times--;
        cout << times << "\n";
    }
}
