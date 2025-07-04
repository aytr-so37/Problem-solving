#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	string s; cin >> s;
	stack<char> stk;
	int answer = 0, temp = 1;
	
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			temp *= 2;
			stk.push('(');
		}
		else if (s[i] == '[') {
			temp *= 3;
			stk.push('[');
		}
		else if (s[i] == ')') {
			if (stk.empty() || stk.top() != '(') {
				answer = 0;
				break;
			}
			if (s[i - 1] == '(') {
				answer += temp;
			}
			temp /= 2;
			stk.pop();
		}
		else if (s[i] == ']') {
			if (stk.empty() || stk.top() != '[') {
				answer = 0;
				break;
			}
			if (s[i - 1] == '[') {
				answer += temp;
			}
			temp /= 3;
			stk.pop();
		}
	}

	if (!stk.empty()) {
		answer = 0;
	}
	cout << answer;
	

}
