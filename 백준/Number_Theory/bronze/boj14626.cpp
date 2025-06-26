#include<iostream>
#include<cctype>
using namespace std;

int main() {
	string str;
	cin >> str;

	int sum = 0;
	int a;
	for (int i = 0; i < 12; ++i) {
		int w = (i % 2 == 0) ? 1 : 3;
		if (isdigit(str[i])) {
			sum += (str[i] - '0') * w;
		}
		else a = w; //빠진 가중치
	}

	int l = str[12] - '0';//마지막 자리

	for (int i = 0; i < 10; ++i) { //로직 분기 시키기 귀찮다 ㅇㅇ
		if ((10-(sum+a*i)%10) % 10 == l) {
			cout << i;
			break;
		}
	}
}
