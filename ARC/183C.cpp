#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

template <int MOD>
struct mint {
	typedef long long ll;
	static const int mod = MOD;
	int x;
	constexpr mint(): x(0) {}
	constexpr mint(ll v) {
		x = v % mod;
		if(x < 0) x += mod;
	}

	friend constexpr mint pow(mint a, ll p) {
		mint ans = 1;
		for(; p; p >>= 1, a *= a) if(p&1) ans *= a;
		return ans;
	}
	friend constexpr mint inv(mint a) { return pow(a, mod-2); }

	explicit constexpr operator int() const { return x; }
	friend constexpr bool operator==(const mint &a, const mint &b) { return a.x == b.x; }
	friend constexpr bool operator!=(const mint &a, const mint &b) { return a.x != b.x; }
	friend constexpr bool operator<=(const mint &a, const mint &b) { return a.x <= b.x; }
	friend constexpr bool operator<(const mint &a, const mint &b) { return a.x < b.x; }
	friend ostream& operator<<(ostream &stream, const mint &v) { return stream << v.x; }
	friend istream& operator>>(istream &stream, mint &v) { return stream >> v.x; }
	constexpr mint& operator+=(const mint &b) { if((x += b.x) >= mod) x -= mod; return *this; }
	constexpr mint& operator-=(const mint &b) { if((x -= b.x) < 0) x += mod; return *this; }
	constexpr mint& operator*=(const mint &b) { x = (1LL * x * b.x) % mod; return *this; }
	constexpr mint& operator/=(const mint &b) { return (*this) *= inv(b); }
	constexpr mint& operator%=(const mint &b) { x %= b.x; return *this; }
	constexpr mint& operator++() { return (*this) += 1; }
	constexpr mint& operator--() { return (*this) -= 1; }
	constexpr mint operator-() { return -x; }
	friend constexpr mint operator+(mint a, const mint &b) { return a += b; }
	friend constexpr mint operator-(mint a, const mint &b) { return a -= b; }
	friend constexpr mint operator*(mint a, const mint &b) { return a *= b; }
	friend constexpr mint operator/(mint a, const mint &b) { return a /= b; }
};
const int mod = 998244353;
using mi = mint<mod>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vi> dp(n, vi(n)), sr(n, vi(n, n));
	vector<mi> fact(n, 1), ifact(n, 1);
	for(int i = 1; i < n; ++i) ifact[i] = inv(fact[i] = fact[i-1]*i);
	while(m--) {
		int l, r, x;
		cin >> l >> r >> x;
		--l; --r; --x;
		for(int k = 0; k <= l; ++k)
			sr[k][x] = min(sr[k][x], r);
	}
	for(int w = 0; w < n; ++w) {
		for(int r = w; r < n; ++r) {
			int l = r-w;
			mi d = 0;
			for(int x = l; x <= r; ++x) if(r < sr[l][x]) {
				const mi a = l < x ? dp[l][x-1] : 1;
				const mi b = x < r ? dp[x+1][r] : 1;
				d += a*b * ifact[x-l] * ifact[r-x];
			}
			dp[l][r] = int(d * fact[w]);
		}
	}
	cout << dp[0][n-1] << endl;

	return 0;
}