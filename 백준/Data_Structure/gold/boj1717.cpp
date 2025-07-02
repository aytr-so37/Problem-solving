#include <iostream>
#include <vector>
using namespace std;
vector<int>parent;
void unite(int, int);
int find(int);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    parent.resize(n + 1, -1);
    
    for (int i = 0; i < n + 1; ++i) {
        parent[i] = i;
    } //initial parent setting

    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0) { // 합치는 연산
            unite(b, c);
        }
        else {
            if (find(b) == find(c)) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
    }



    
}

void unite(int x, int y) {
    if (find(x) != find(y)) {
        parent[find(y)] = parent[x];
    }
}

int find(int a) {
    if (parent[a] == a) {
        return a;
    }
    else {
        return parent[a]=find(parent[a]);
    }

}
