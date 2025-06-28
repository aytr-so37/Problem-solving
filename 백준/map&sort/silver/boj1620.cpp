#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;
	//N:포켓몬 개수 , M: 문제 개수

	unordered_map<string,string>v;

	for (int i = 0; i < N; ++i) {
		string a; cin >> a;

		v.insert({ a,to_string(i + 1) });
		v.insert({ to_string(i + 1),a });
	}

	for (int i = 0; i < M; ++i) {
		string a; cin >> a;
		cout << v[a] << "\n";
	}
}
