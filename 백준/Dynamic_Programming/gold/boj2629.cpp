#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int>v(N, -1);
    for (int i = 0; i < N; ++i) {
        int input; cin >> input;
        v[i] = input;
    } // 추 무게
    int dx[3] = { -1,0,1 };

    vector<int>a;
    a.push_back(0);

    for (int i = 0; i < N; ++i) { // 추 사용범위
        int temp = a.size();
        for (int j = 0; j < temp; ++j) { // 표현가능했던 무게들
            for (int k = 0; k < 3; ++k) {
                if (find(a.begin(), a.end(), a[j] + v[i] * dx[k]) == a.end()) {
                    a.push_back(a[j] + v[i] * dx[k]);
                }
            }
        }
    }

    int aa; cin >> aa;
    for (int i = 0; i < aa; ++i) {
        int target; cin >> target;
        if (find(a.begin(), a.end(), target) != a.end()) {
            cout << "Y ";
        }
        else {
            cout << "N ";
        }
    }


}

