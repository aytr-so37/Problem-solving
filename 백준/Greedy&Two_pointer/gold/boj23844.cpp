#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vb = vector<bool>;

vvi edges; // 간선 저장
vvi p_edges;
vi child; // 해당 간선에 연결된 하위 정점의 개수
vvi depth(10010); // 해당 depth에 있는 정점들
vi cnt;


int dfs_impl(int,int); //initial dfs
vb visited;
void del(int,int);




int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K; cin >> N >> K;
    edges = vvi(N);
    p_edges = vvi(N); // 부모 - 자식 순의 간선만

    for (int i = 0; i < N - 1; ++i) {
        int a, b; cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    child = vi(N,0); 
    visited = vb(N, false);

    depth[1].push_back(0);
    visited[0] = true;
    child[0] = dfs_impl(0,1);
    cnt = vi(10010, 0);
    // 1번 간선에서 dfs를 돌며 부모-자식 간선만 추리기
    // + 연결된 하위 정점 정리

    for (int i = 1; i < 10010; ++i) {
        if (depth[i].size()-cnt[i] == 0) {
            cout << child[0];
            break; // 마무리
        }
        if (depth[i].size()-cnt[i] <= K) continue; //k이하
        
        else { // 기준보다 많은 경우
            sort(depth[i].begin(), depth[i].end(), [](int a, int b) {
                return child[a] < child[b];
                });
            // 잘려도 여파가 적은 것부터
            int aa = 0;
            while (depth[i].size() - cnt[i] > K) {
                del(depth[i][aa],i);
                child[0] -= child[depth[i][aa]];
                aa++;
            }
        }
    }
}

int dfs_impl(int x,int prev) {
    int sum = 0;
    for (int c : edges[x]) {
        if (!visited[c]) { // not visited
            depth[prev + 1].push_back(c);
            visited[c] = true;
            sum += dfs_impl(c, prev + 1);

            p_edges[x].push_back(c); 
            // only p to c
        }
    }
    child[x] = sum+1;
    return sum+1;
}

void del(int x,int prev) { // x는 자르는 가지의 노드 번호
    cnt[prev]++;
    int size = p_edges[x].size(); // 이걸 가지고 두께 계산에 사용
    for (int c : p_edges[x]) {
        del(c,prev+1);
    }
}
