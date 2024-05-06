#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cassert>

using namespace std;
using ll = long long;
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

	friend mint pow(mint a, ll p) {
		mint ans = 1;
		for(; p; p >>= 1, a *= a) if(p&1) ans *= a;
		return ans;
	}
	friend mint inv(mint a) { return pow(a, mod-2); }

	explicit operator int() const { return x; }
	friend bool operator==(const mint &a, const mint &b) { return a.x == b.x; }
	friend bool operator!=(const mint &a, const mint &b) { return a.x != b.x; }
	friend bool operator<=(const mint &a, const mint &b) { return a.x <= b.x; }
	friend bool operator<(const mint &a, const mint &b) { return a.x < b.x; }
	friend ostream& operator<<(ostream &stream, const mint &v) { return stream << v.x; }
	friend istream& operator>>(istream &stream, mint &v) { return stream >> v.x; }
	mint& operator+=(const mint &b) { if((x += b.x) >= mod) x -= mod; return *this; }
	mint& operator-=(const mint &b) { if((x -= b.x) < 0) x += mod; return *this; }
	mint& operator*=(const mint &b) { x = (1LL * x * b.x) % mod; return *this; }
	mint& operator/=(const mint &b) { return (*this) *= inv(b); }
	mint& operator%=(const mint &b) { x %= b.x; return *this; }
	mint& operator++() { return (*this) += 1; }
	mint& operator--() { return (*this) -= 1; }
	mint operator-() { return -x; }
	friend mint operator+(mint a, const mint &b) { return a += b; }
	friend mint operator-(mint a, const mint &b) { return a -= b; }
	friend mint operator*(mint a, const mint &b) { return a *= b; }
	friend mint operator/(mint a, const mint &b) { return a /= b; }
};
const int MOD = 998244353;
using mi = mint<MOD>;

// Need to compute a generator g of T before
template <typename T>
void NTT(vector<T> &P, T g, bool invert=false) {
	int n = P.size();
	assert((T::mod-1) % n == 0);
	g = pow(g, (T::mod-1) / n);
	if(invert) g = inv(g);

	// swap indices with their mirror binary
	for(int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for(; j&bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(P[i], P[j]);
	}

	// Transform
	for(int len = 2; len <= n; len <<= 1) {
		int half = len >> 1;
		T wl = g;
		for(int i = len; i < n; i <<= 1) wl *= wl;
		for(int i = 0; i < n; i += len) {
			T w = 1;
			for(int j = 0; j < half; ++j) {
				T even = P[i+j];
				T odd = P[i+half+j] * w;
				P[i+j] = even + odd;
				P[i+half+j] = even - odd;
				w *= wl;
			}
		}
	}

	// Divide by n if inverse
	if(invert) {
		T inv_n = inv(T(n));
		for(T &x : P) x *= inv_n;
	}
}

template <typename T>
void NTT_mult_inplace(vector<T> &P, vector<T> &Q, T g) {
	int size = 1, n = P.size() + Q.size() - 1;
	while(size < n) size <<= 1;
	P.resize(size, 0);
	Q.resize(size, 0);
	NTT<T>(P, g);
	NTT<T>(Q, g);
	for(int i = 0; i < size; ++i) P[i] *= Q[i];
	NTT<T>(P, g, true);
	P.resize(n);
}

using Poly = vector<mi>;

struct Cmp {
	Cmp() = default;
	bool operator()(const Poly &a, const Poly &b) const {
		return a.size() > b.size();
	}
};

const mi G = 3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> count(3001, 0);
	mi m = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++count[a];
		m += a;
	}

	priority_queue<Poly, vector<Poly>, Cmp> Q;
	for(int a = 2; a <= 3000; ++a) if(count[a]) {
		Poly p(count[a]+1, 1);
		for(int i = 1; i <= count[a]; ++i) p[i] = p[i-1]*a*(count[a]+1-i)/i;
		Q.emplace(move(p));
	}

	while(Q.size() > 1) {
		Poly p = move(Q.top()); Q.pop();
		Poly q = move(Q.top()); Q.pop();
		NTT_mult_inplace(p, q, G);
		Q.emplace(move(p));
	}

	const Poly p = move(Q.top()); Q.pop();

	mi ans = 1;
	mi den = 1, num = 1;
	for(int i = 1; i <= n; ++i) {
		den *= (m+1-i);
		num *= i;
		ans += p[i] * num / den;
	}
	cout << ans << endl;

	return 0;
}