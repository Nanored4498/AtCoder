#include <iostream>
#include <vector>

using namespace std;

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
const int MOD = 998244353;
using mi = mint<MOD>;

template<typename T>
struct Fenwick {
	inline static int LSB(int i) { return i&(-i); }
	vector<T> v;

	Fenwick() = default;
	Fenwick(int n): v(n+1, 0) {}

	void init() {
		for(int i = 1; i < (int) v.size(); ++i) v[i] += v[i-1];
		for(int i = v.size()-1; i > 0; --i) v[i] -= v[i-LSB(i)];
	}

	void add(int i, T x) {
		for(; i < (int) v.size(); i += LSB(i)) v[i] += x;
	}
	void set(int i, T x) { add(i, x - querry(i, i)); }

	T querry(int i) {
		T ans = 0;
		for(; i > 0; i -= LSB(i)) ans += v[i];
		return ans;
	}
	T querry(int a, int b) { return querry(b) - querry(a-1); }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	for(int &x : p) cin >> x;

	Fenwick<int> a(n);
	mi v = 0;
	for(int i = 0; i < k; ++i) a.add(p[i], 1);
	for(int i = k; i < n; ++i) {
		v += a.querry(p[i]+1, n);
		a.add(p[i], 1);
	}
	for(int i = k; i < n; ++i) a.add(p[i], -1);


	mi ans = v;
	for(int i = k; i < n; ++i) {
		a.add(p[i-k], -1);
		v += a.querry(1, p[i-k]-1) - a.querry(p[i]+1, n);
		a.add(p[i], 1);
		ans += v;
	}

	ans /= n-k+1;
	ans += mi(k) * (k-1) / 4;
	cout << ans << endl;

	return 0;
}