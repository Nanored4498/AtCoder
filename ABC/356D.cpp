#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

const ll MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	for(int i = 0; i < 60; ++i) if((m>>i)&1) {
		ans = (ans + (n>>(i+1)) * (1LL<<i)) % MOD;
		if((n>>i)&1) ans = (ans + 1 + (n&((1LL<<i)-1LL))) % MOD;
		// cerr << ((n>>(i+1)) * (1LL<<i)) + (1 + (n&((1LL<<i)-1LL))) << endl;
	}
	cout << ans << endl;

	return 0;
}