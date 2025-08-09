#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ull = unsigned long long;

vector<ull>primes;
void build_primes(ull);

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ull N; cin >> N;	
	primes.push_back(0); // 1basedindex
	build_primes(N); 

	vector<ull>prefix_sum(primes.size());
	unordered_set<ull>ps;                  
	prefix_sum[0] = 0;
	for (ull i = 1; i < primes.size(); ++i) {
		prefix_sum[i] = prefix_sum[i - 1] + primes[i];
		ps.insert(prefix_sum[i]); // find 쓰기 위한
	}

	ull cnt = 0;
	for (ull i = 0; i < prefix_sum.size(); ++i) {
		if (ps.find(prefix_sum[i] + N) != ps.end()) cnt++;
	}

	cout << cnt;
}

void build_primes(ull a) {
	vector<bool>sieve(a + 1,false);
	for (ull i = 2; i <= a; ++i) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (ull j = 1; j * i <= a; ++j) {
				sieve[i * j] = true;
			}
		}
	}
}
