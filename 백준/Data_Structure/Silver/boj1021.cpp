#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

int rotate(int, deque<int>&);

int main()
{
	int N, M; cin >> N >> M;

	deque<int>v;
	for (int i = 0; i < N; ++i) {
		v.push_back(i + 1);
	} // 처음 deque setting

	int result = 0;
	for (int i = 0; i < M; ++i) {
		int a; cin >> a; // 이번에 찾을 수
		result += rotate(a, v);
	}

	cout << result << "\n";
}

int rotate(int goal, deque<int>& v) {
	deque<int>::iterator it = find(v.begin(), v.end(), goal);
	int idx = distance(v.begin(), it); // goal의 index
	int result = 0;

	if (v.size() - idx > idx) { // 왼쪽으로 회전해야할 때
		for (int i = 0; i < idx; ++i) {
			int temp = v.front();
			v.pop_front();
			v.push_back(temp);
			result++;
		}
		v.pop_front();
	}
	else {
		for (int i = 0; i < v.size() - idx; ++i) {//오른쪽으로 회전해야할 때
			int temp = v.back();
			v.pop_back();
			v.push_front(temp);
			result++;
		}
		v.pop_front();
	}

	return result;
}

