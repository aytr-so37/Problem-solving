#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T; //test case
    for (int i = 0; i < T; ++i) {
        int N, M; cin >> N >> M;
        // N: 문서의 개수
        // M: 궁금한 문서의 idx
        vector<int>arr(N); // original arr
        vector<int>v(N);   // sort arr     
        vector<int>re(N, 0); // 출력 순서 표시 arr
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            v[i] = a; arr[i] = a;
        }// 일단 vec으로 받기
        sort(v.begin(), v.end()); // 오름차순 sort
               
        int idx = 1;
        int k = 0;
        while (idx <= N) { // 모든 출력 순서를 다 확정지을 때까지
            int ridx = k % N;
            if (re[ridx] == 0 && arr[ridx] == v[N - idx]) { // 빼야할 때
                re[ridx] = idx;             
                idx++;
            }
            k++;
        }

        cout << re[M] << "\n";


    }
}
