#include <iostream>
#include <vector>
using namespace std;

void recursion(int, int, int,vector<vector<int>>&);

int main()
{
    int height;
    cin >> height;

    int width = height / 3 * 5 + height / 3 - 1;

    vector<vector<int>>graph(height, vector<int>(width, 0));
    // 0으로 초기화 해준 뒤 별이 있을 곳에만 1로 update 해줄 예정

    recursion(0, width / 2, height,graph);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << ((graph[i][j]) ? '*' : ' ');
        }
        cout << "\n";
    }

}

void recursion(int x, int y, int level, vector<vector<int>>& graph) {
    if (level == 3) { // 제일 작은 level
        graph[x][y] = 1;
        graph[x + 1][y - 1] = 1;
        graph[x + 1][y + 1] = 1;
        for (int i = 0; i < 5; ++i) graph[x + 2][y - 2 + i] = 1;
    }
    else {
        recursion(x, y, level / 2, graph);
        recursion(x + level / 2, y - level / 2, level / 2, graph);
        recursion(x + level / 2, y + level / 2, level / 2, graph);
    }
}
