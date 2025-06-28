#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;

	unordered_set<string>v;
	for (int i = 0; i < N; ++i) {
		string a, b;
		cin >> a >> b;
		if (b == "enter") v.insert(a);
		else v.erase(a);
	}

	vector<string>vv(v.begin(), v.end());
	// unordered_set -> vector

	sort(vv.begin(), vv.end(), greater<string>());

	for (int i = 0; i < vv.size(); ++i) {
		cout << vv[i] << "\n";
	}

}
