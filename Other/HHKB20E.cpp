#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const ll MOD = 1e9+7;

ll pow(ll x, ll p) {
	ll ans = 1;
	while(p) {
		if(p&1) ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		p >>= 1;
	}
	return ans;
}

inline ll inv(ll x) {
	return pow(x, MOD-2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int W, H;
	cin >> H >> W;
	vector<string> S(H);
	for(int i = 0; i < H; ++i) cin >> S[i];

	ll K = 0;
	vvl dpx(H, vl(W)), dpy(H, vl(W));
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j) {
			if(S[i][j] == '.') {
				dpx[i][j] = i == 0 ? 1 : dpx[i-1][j]+1;
				dpy[i][j] = j == 0 ? 1 : dpy[i][j-1]+1;
				++ K;
			} else {
				dpx[i][j] = dpy[i][j] = 0;
			}
		}
	}
	for(int i = H-1; i >= 0; --i) {
		for(int j = W-1; j >= 0; --j) if(S[i][j] == '.') {
			if(i+1 < H) dpx[i][j] = max(dpx[i][j], dpx[i+1][j]);
			if(j+1 < W) dpy[i][j] = max(dpy[i][j], dpy[i][j+1]);
		}
	}
	ll ans = (K * pow(2, K)) % MOD;
	
	// Remove cases
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j) if(S[i][j] == '.') {
			ans = (ans + MOD - pow(2, K - (dpx[i][j] + dpy[i][j] - 1))) % MOD;
		}
	}

	cout << ans << endl;

	return 0;
}