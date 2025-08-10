#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using pii = pair<int, int>;

vector<int>parent;
void unite(int, int);
int find(int);


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    //N: 아이들 수 M: 아이들의 관계 수 K: 공명 아이 수
    vector<int>candy(N);

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        candy[i] = a;
    } // candy set

    parent.resize(N);
    for (int i = 0; i < N; ++i) parent[i] = i;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        unite(a-1, b-1); // 0basedindex
    }

    unordered_map<int,pii >um;
    
    for (int i = 0; i < N; ++i) {
        int root = find(i);
        if (um.find(root) == um.end()) {
            um[root] = { 1,candy[i] };
        }
        else {
            um[root].first++;
            um[root].second += candy[i];
        }
    } // 뭉텅이랑 그 뭉텅이의 사탕 수로 

    vector<pair<int, pii>>v(um.begin(), um.end());
    // index 접근을 위해서

    for (int i = 0; i < v.size(); ++i) v[i].first = i;
    // index dp 편하도록 index 변화

    vector<vector<int>>dp(v.size()+1, vector<int>(K + 1, 0));
    // dp[i][w] == i 번째 물건까지 고려했을 때 w 무게의 최대가치

    int mx = 0;
    for (int i = 0; i < v.size(); ++i) dp[i][0] = 0;
    for (int i = 1; i <= v.size(); i++) { // 아이템
        int weight = v[i - 1].second.first;
        int value = v[i - 1].second.second;
        for (int w = 1; w <= K-1; w++) { // 무게
            dp[i][w] = dp[i - 1][w]; // 안 넣는 경우
   
            if (w >= weight) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weight] + value);
                mx = max(mx, dp[i][w]);
            }
            
        }
    }

    cout << mx;


}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (b < a) {
        parent[a] = b;
    }
    else parent[b] = a;
}

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
