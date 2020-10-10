#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const ll MOD = 1e9+7;

inline void mult(ll &a, ll b) {
	a = (a*b) % MOD;
}

inline void add(ll &a, ll b) {
	a = (a+b) % MOD;
}

ll pow(ll x, ll p) {
	ll ans = 1;
	while(p) {
		if(p&1) mult(ans, x);
		mult(x, x);
		p >>= 1;
	}
	return ans;
}

inline ll inv(ll x) {
	return pow(x, MOD-2);
}

void multP(vl &P, ll c) { // P = P * (X - c)
	P.push_back(P.back());
	for(int i = P.size()-2; i > 0; --i) P[i] = (P[i-1] + MOD - (c*P[i]) % MOD) % MOD;
	mult(P[0], MOD-c);
}

void divP(vl &P, ll c) { // P = P / (X - c)
	ll ic = inv(c);
	mult(P[0], MOD-ic);
	for(int i = 1; i < P.size(); ++i) P[i] = ((P[i-1] + MOD - P[i]) * ic) % MOD;
	P.pop_back(); 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vl L(N), R(N);
	for(int i = 0; i < N; ++i) cin >> L[i] >> R[i];

	vector<pair<ll, int>> v;
	for(int i = 0; i < N; ++i) {
		v.emplace_back(L[i], -1);
		v.emplace_back(R[i], i);
	}
	sort(v.begin(), v.end());

	ll PRL = 1;
	for(int i = 0; i < N; ++i) mult(PRL, R[i] - L[i]);
	vl fac(N+2, 1), invn(N+2);
	for(ll i = 1; i <= N+1; ++i) fac[i] = (i * fac[i-1]) % MOD;
	for(int i = 1; i < N+2; ++i) invn[i] = inv(i);
	ll NPRL = (fac[N+1] * PRL) % MOD;
	ll NPRL2 = fac[N+1];

	vl P = {1};
	int s = 0;
	ll x = 0;
	ll ans = 0;
	for(auto p : v) {
		ll y = p.first;
		add(ans, (y - x) * NPRL);
		if(s == N) {
			ll xp = 1, yp = 1;
			for(int i = 0; i < P.size(); ++i) {
				mult(xp, x);
				mult(yp, y);
				ll integral = ((xp + MOD - yp) * P[i]) % MOD;
				mult(integral, invn[i+1]);
				mult(integral, NPRL2);
				add(ans, integral);
			}
		}
		if(p.second == -1) {
			++ s;
			multP(P, y);
		} else {
			divP(P, L[p.second]);
			mult(NPRL2, y - L[p.second]);
		}
		x = y;
	}
	cout << ans << endl;

	return 0;
}