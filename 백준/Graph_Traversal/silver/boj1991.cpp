#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs_impl(int,const vector<pair<int,int>>&);
vector<int>preorder; //전위 순회
vector<int>inorder; // 중위 순회
vector<int>postorder; // 후위 순회

int main()
{
	int N; cin >> N;
	vector<pair<int, int>>v(N);
	for (int i = 0; i < N; ++i) {
		char a, b, c; cin >> a >> b >> c;
		int left = (b != '.') ? (b - 'A') : -1;
		int right = (c != '.') ? (c - 'A') : -1;
		v[a - 'A'] = { left,right };
	} //setting (숫자로)

	preorder.push_back(0);
	dfs_impl(0, v);
	
	for (int i : preorder) {
		cout << (char)(i + 'A');
	}
	cout << "\n";

	for (int i : inorder) {
		cout << (char)(i + 'A');
	}
	cout << "\n";

	for (int i : postorder) {
		cout << (char)(i + 'A');
	}
	cout << "\n";



}

void dfs_impl(int a, const vector<pair<int,int>>& graph) {
	if (a == -1) return;
	
	int left = graph[a].first;
	int right = graph[a].second;

	if (left != -1) preorder.push_back(left);
	dfs_impl(left, graph);

	inorder.push_back(a);

	if(right != -1) preorder.push_back(right);
	dfs_impl(right, graph);

	postorder.push_back(a);
}
