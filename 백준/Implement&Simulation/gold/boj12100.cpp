#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;

int N;
int mx = 0;
vvi f1(const vvi&); // 위
vvi f2(const vvi&); // 오른
vvi f3(const vvi&); // 아래
vvi f4(const vvi&); // 왼

int main()
{
    cin >> N;
    vvi v(N, vi(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int a; cin >> a;
            v[i][j] = a;
        }
    } // initial set

    
    queue<pair<vvi, int>>bfs;
    bfs.push({ v,0 });
    while (!bfs.empty()) {
         vvi tmap = bfs.front().first;
         int t = bfs.front().second; 
         bfs.pop();

         if (t < 10) {
             vvi t1 = f1(tmap);
             if (tmap != t1) bfs.push({ t1,t + 1 });
             vvi t2 = f2(tmap);
             if (tmap != t2) bfs.push({ t2,t + 1 });
             vvi t3 = f3(tmap);
             if (tmap != t3) bfs.push({ t3,t + 1 });
             vvi t4 = f4(tmap);
             if (tmap != t4) bfs.push({ t4,t + 1 });
         }
    }

    cout << mx;
}

vvi f1(const vvi& a) { // 위로 옮기는 경우 
    vvi result = a;

    for (int i = 0; i < N; ++i) {
        vector<int>temp;
        for (int j = 0; j < N; ++j) {
            if (a[j][i] != 0) {
                temp.push_back(a[j][i]);
            }
        } // 0이 아닌 경우만 push

        vector<int>t2; // 겹쳐진 vec
        int idx = 0;
        while (idx<temp.size()) {
            if (idx + 1 < temp.size() && temp[idx] == temp[idx + 1]) {
                t2.push_back(temp[idx] *2);
                idx += 2;
            }
            else {
                t2.push_back(temp[idx]);
                idx++;
            }
        }

        for (int j = 0; j < t2.size(); ++j) {
            result[j][i] = t2[j];
            mx = max(mx, t2[j]); // 최대 값 블럭 계산
        }
        for (int j = t2.size(); j < N; ++j) {
            result[j][i] = 0;
        }
    }

    return result;
}

vvi f2(const vvi& a) { // 오른쪽으로
    vvi result = a;

    for (int i = 0; i < N; ++i) {
        vector<int>temp;
        for (int j = 0; j < N; ++j) {
            if (a[i][j] != 0) {
                temp.push_back(a[i][j]);
            }
        } // 0이 아닌 경우만 push

        vector<int>t2; // 겹쳐진 vec
        int idx = temp.size()-1;
        while (idx >= 0) {
            if (idx - 1 >= 0 && temp[idx] == temp[idx - 1]) {
                t2.push_back(temp[idx] *2);
                idx -= 2;
            }
            else {
                t2.push_back(temp[idx]);
                idx--;
            }
        }

        for (int j = 0; j < t2.size(); ++j) {
            result[i][N-j-1] = t2[j];
            mx = max(mx, t2[j]); // 최대 값 블럭 계산
        }
        for (int j = t2.size(); j < N; ++j) {
            result[i][N-j-1] = 0;
        }
    }

    return result;
}

vvi f3(const vvi& a) { // 아래로
    vvi result = a;

    for (int i = 0; i < N; ++i) {
        vector<int>temp;
        for (int j = 0; j < N; ++j) {
            if (a[j][i] != 0) {
                temp.push_back(a[j][i]);
            }
        } // 0이 아닌 경우만 push

        vector<int>t2; // 겹쳐진 vec
        int idx = temp.size()-1;
        while (idx >= 0) {
            if (idx - 1 >=0 && temp[idx] == temp[idx - 1]) {
                t2.push_back(temp[idx] *2);
                idx -= 2;
            }
            else {
                t2.push_back(temp[idx]);
                idx--;
            }
        }

        for (int j = 0; j < t2.size(); ++j) {
            result[N-j-1][i] = t2[j];
            mx = max(mx, t2[j]); // 최대 값 블럭 계산
        }
        for (int j = t2.size(); j < N; ++j) {
            result[N-j-1][i] = 0;
        }
    }

    return result;
}

vvi f4(const vvi& a) { // 왼쪽으로 
    vvi result = a;

    for (int i = 0; i < N; ++i) {
        vector<int>temp;
        for (int j = 0; j < N; ++j) {
            if (a[i][j] != 0) {
                temp.push_back(a[i][j]);
            }
        } // 0이 아닌 경우만 push

        vector<int>t2; // 겹쳐진 vec
        int idx = 0;
        while (idx < temp.size()) {
            if (idx + 1 < temp.size() && temp[idx] == temp[idx + 1]) {
                t2.push_back(temp[idx] *2);
                idx += 2;
            }
            else {
                t2.push_back(temp[idx]);
                idx++;
            }
        }

        for (int j = 0; j < t2.size(); ++j) {
            result[i][j] = t2[j];
            mx = max(mx, t2[j]); // 최대 값 블럭 계산
        }
        for (int j = t2.size(); j < N; ++j) {
            result[i][j] = 0;
        }
    }

    return result;
}
