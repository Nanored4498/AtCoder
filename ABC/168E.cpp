#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	map<pll, ll> m;
	ll c0 = 0;
	while(N --> 0) {
		ll a, b;
		cin >> a >> b;
		if(a == 0 && b == 0) { ++c0; continue; }
		ll g = __gcd(abs(a), abs(b));
		if(b < 0 || (b == 0 && a < 0)) g = -g;
		++ m[{a/g, b/g}];
	}
	ll res = 1;
	for(auto &p : m) {
		if(p.second < 0) continue;
		ll a = p.first.first, b = p.first.second;
		ll e = b, f = -a;
		if(f < 0 || (f == 0 && e < 0)) { e = -e; f = -f; }
		pll pef = {e, f};
		ll add = 0, add2 = 0;
		while(p.second --> 0) add = (2*add + res) % MOD;
		if(m.count(pef)) while(m[pef] --> 0) add2 = (2*add2 + res) % MOD;
		res = (res + add + add2) % MOD;
	}
	res = (res+MOD-1+c0) % MOD;
	cout << res << endl;

	return 0;
}