#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int BFS_impl(int, int, unordered_map<int,int>&);

int main()
{
    unordered_map<int,int>visited; // 평소 bfs처럼 하려면 너무 vector가 커지니 이렇게 합시다
                               // node 번호는 매우 크고, 실제 방문할 점들은 별로 크기 않을 때
    
    int A, B; // A->B
    cin >> A >> B;
    cout << BFS_impl(A, B, visited);
}

int BFS_impl(int start, int goal, unordered_map<int,int>& visited) {
    queue<int>bfs;
    bfs.push(start);
    visited.insert({ start,1 });
    while (!bfs.empty()) {
        int temp = bfs.front();
        int a = visited[temp];
        bfs.pop();

        if (visited.find(2 * temp) ==visited.end() && temp<=1e9/2) {
            if (2 * temp == goal) return a + 1;
            visited.insert({ 2 * temp, a + 1 });
            bfs.push(2*temp);
            
        }
        if (visited.find(10 * temp+1) == visited.end() && temp<1e8) {
            if (10 * temp + 1 == goal) return a + 1;
            visited.insert({ 10 * temp + 1, a + 1 });
            bfs.push(10 * temp + 1);
        }
    }
    return -1;
}

