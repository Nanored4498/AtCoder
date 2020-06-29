#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const ll MOD = 1e9+7;

inline ll pow(ll x, ll p) {
	ll ans = 1;
	while(p > 0) {
		if(p&1) ans = (ans*x) % MOD;
		p >>= 1;
		x = (x*x) % MOD;
	}
	return ans;
}
inline ll inv(ll x) { return pow(x, MOD-2); }
vl fac;
inline ll C(int k, int n) {
	return (fac[n] * inv((fac[n-k]*fac[k]) % MOD)) % MOD; 
}
inline void mul(ll &a, const ll &b) {
	a = (a*b) % MOD;
}

int main() {
	int N, M;
	cin >> N >> M;
	fac.resize(M+1);
	fac[0] = 1;
	ll ans = 0;
	for(int i = 1; i <= M; ++i) fac[i] = (i*fac[i-1]) % MOD;
	for(int i = 0; i <= N; ++i) { // i: number of equality position
		ll add = C(i, N); // choose equality positions
		mul(add, C(i, M)); // choose values of equality
		mul(add, fac[i]); // choose order of values
		mul(add, C(N-i, M-i)); // choose remaining values of A
		mul(add, fac[N-i]); // choose their order
		mul(add, C(N-i, M-i)); // choose remaining values of B
		mul(add, fac[N-i]); // choose their order
		if(i&1) ans = (ans+MOD-add) % MOD;
		else ans = (ans+add) % MOD;
	}
	cout << ans << endl;
	return 0;
}