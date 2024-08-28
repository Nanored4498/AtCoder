#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
using vi = vector<int>;

template<typename T>
struct Fenwick {
	#define LSB(i) ((i)&(-(i)))
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

	int n, q;
	cin >> n;
	Fenwick<ll> a(n);
	map<int, ll> b;
	for(int i = 1; i <= n; ++i) cin >> a.v[i];
	a.init();
	for(int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		if(x > 1) b[i] = x;
	}
	cin >> q;
	while(q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		if(c == '1') a.set(x, y);
		else if(c == '2') {
			if(y > 1) b[x] = y;
			else b.erase(x);
		} else {
			auto it = b.upper_bound(x);
			ll ans = 0;
			while(it != b.end() && it->first <= y) {
				if(x < it->first) ans += a.querry(x, it->first-1);
				ans = max(ans + a.querry(it->first, it->first), ans * it->second);
				x = it->first+1;
				++it;
			}
			if(x <= y) ans += a.querry(x, y);
			cout << ans << '\n';
		}
	}

	return 0;
}