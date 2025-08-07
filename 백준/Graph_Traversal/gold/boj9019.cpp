#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int D(int); int S(int);
int L(int); int R(int);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        vector<string>v(10001, "-");
        int A, B; cin >> A >> B;
        // A: initial value
        // B: goal

        // bfs 구현
        queue<int>bfs;
        bfs.push(A);
        v[A] = "";
        while (!bfs.empty()) {
            int temp = bfs.front();
            bfs.pop();
            string ts = v[temp];
            int d = D(temp); 
            int s = S(temp);
            int l = L(temp);
            int r = R(temp);
            if (v[d] == "-") {
                v[d] = ts + 'D';
                if (d == B) {
                    cout << v[d] << "\n";
                    break;
                }
                bfs.push(d);
            }
            if (v[s] == "-") {
                v[s] = ts + 'S';
                if (s == B) {
                    cout << v[s] << "\n";
                    break;
                }
                bfs.push(s);
            }
            if (v[l] == "-") {
                v[l] = ts + 'L';
                if (l == B) {
                    cout << v[l] << "\n";
                    break;
                }
                bfs.push(l);
            }
            if (v[r] == "-") {
                v[r] = ts+'R';
                if (r == B) {
                    cout << v[r] << "\n";
                    break;
                }
                bfs.push(r);
            }

        }

    }
}

int D(int a) {
    return ((a * 2) % 10000);
}
int S(int a) {
    return ((a + 9999) % 10000);
 }
int L(int a) {
    int t = a / 1000;
    return ((a * 10 + t) % 10000);
}
int R(int a) {
    int t = a % 10;
    return (a / 10 + t * 1000);
}
