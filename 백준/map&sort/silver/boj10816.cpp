#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    unordered_map<int,int>v;


    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        if (v.find(input) != v.end()) {
            v[input]++;
        }
        else {
            v.insert({ input,1 });
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int input;
        cin >> input;
        if (v.find(input) != v.end()) cout << v[input] << " ";
        else cout << "0 ";
    }
}
