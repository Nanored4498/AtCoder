#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;

const ll MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	vi X(m);
	for(int &x : X) {
		cin >> x;
		--x;
	}

	const int M = 1<<m;
	vector<vi> t(M, vi(m));
	for(int u = 0; u < M; ++u) {
		for(int i = 0; i < m; ++i) {
			int v = u & (M-1 - (1<<i));
			for(int j = 0; j < m; ++j)
				if(X[j] == i) v |= (1<<j);
			t[u][i] = v;
		}
	}

	vector<ll> dp(M, 0), dp2;
	dp.back() = 1;
	while(n--) {
		dp2.assign(M, 0);
		for(int u = 0; u < M; ++u) {
			for(int i = 0; i < m; ++i) if((u>>i)&1) {
				int v = t[u][i];
				dp2[v] = (dp2[v] + dp[u]) % MOD;
			}
		}
		swap(dp, dp2);
	}

	ll ans = 0;
	for(ll x : dp) ans = (ans + x) % MOD;
	cout << ans << endl;

	return 0;
}