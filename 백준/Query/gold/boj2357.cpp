#include <iostream>
#include <vector>
using namespace std;

int minn(int, int);
int maxx(int, int);
vector<int>min_tree, max_tree;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;
	//N: 수 개수 M: 쿼리 개수

	min_tree.resize(4 * N,1e9);
	max_tree.resize(4 * N,0);
	int size = 1;
	while (size < N) size *= 2;

	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		min_tree[i + size] = a;
		max_tree[i + size] = a;
	}

	for (int i = 4 * N - 1; i >= 2; --i) {
		min_tree[i / 2] = min(min_tree[i / 2], min_tree[i]);
		max_tree[i / 2] = max(max_tree[i / 2], max_tree[i]);
	} // initial tree setting

	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		cout << minn(a + size - 1, b + size - 1) << " " << maxx(a + size - 1, b + size - 1) << "\n";
	}
}

int minn(int start, int end) {
	if (end < start) return 1e9;

	if (start % 2 == 1 && end % 2 == 0) {
		return min(min_tree[end],min(min_tree[start], minn((start + 1) / 2, (end - 1) / 2)));
	}
	else if (start % 2 == 1) {
		return min(min_tree[start], minn((start + 1) / 2, end / 2));
	}
	else if (end % 2 == 0) {
		return min(min_tree[end], minn(start / 2, (end - 1) / 2));
	}
	else {
		return minn(start / 2, end / 2);
	}
}

int maxx(int start, int end) {
	if (end < start)return 0;

	if (start % 2 == 1 && end % 2 == 0) {
		return max(max_tree[end], max(max_tree[start], maxx((start + 1) / 2, (end - 1) / 2)));
	}
	else if (start % 2 == 1) {
		return max(max_tree[start], maxx((start + 1) / 2, end / 2));
	}
	else if (end % 2 == 0) {
		return max(max_tree[end], maxx(start / 2, (end - 1) / 2));
	}
	else {
		return maxx(start / 2, end / 2);
	}
}
