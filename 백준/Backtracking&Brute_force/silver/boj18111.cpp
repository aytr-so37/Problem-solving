#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, B;
    cin >> N >> M >> B;
    
    int sum = 0;
    sum += B;
    vector<vector<int>>v(N, vector<int>(M, -1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int a; cin >> a;
            v[i][j] = a;
            sum += a;
        }
    }
    int max_h = sum / (N * M);

    int min_time = 1e9;
    int height = -1;
    for (int i = 0; i <= max_h; ++i) {
        int time = 0;
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (v[j][k] > i) {
                    time += (v[j][k] - i) * 2;
                }
                else {
                    time += (i - v[j][k]);
                }
            }
        }
        if (min_time >= time) {
            min_time = time;
            height = i;
        }
    }
    cout << min_time << " " << height;
}

