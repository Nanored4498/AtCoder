#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int M = 2e6+5;

ll fac[M], ifac[M];

ll inv(ll x) {
	ll ans = 1;
	ll p = MOD-2;
	while(p > 0) {
		if(p&1) ans = (ans*x) % MOD;
		p >>= 1;
		x = (x*x) % MOD;
	}
	return ans;
}

ll ifa(int i) {
	if(!ifac[i]) ifac[i] = inv(fac[i]);
	return ifac[i];
}

ll C(int n, int k) {
	return (((fac[n]*ifa(k)) % MOD) * ifa(n-k)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fac[0] = 1;
	for(int i = 1; i < M; ++i) fac[i] = (fac[i-1]*i) % MOD;

	int K;
	cin >> K;
	string S;
	cin >> S;
	int n = S.size();
	ll ans = 0;
	ll p25 = 1, p26 = 1, i26 = inv(26);
	for(int k = 0; k < K; ++k) p26 = (p26*26) % MOD;
	for(int k = 0; k <= K; ++k) {
		ll a = (p25 * C(k+n-1, n-1)) % MOD;
		a = (a * p26) % MOD;
		ans = (ans + a) % MOD;
		p25 = (p25*25) % MOD;
		p26 = (p26*i26) % MOD;
	}
	cout << ans << "\n";

	return 0;
}