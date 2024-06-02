#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

	const int m = 1e6+5;
	int n;
	cin >> n;
	Fenwick<int> f(m);
	while(n--) {
		int a; cin >> a;
		++ f.v[a];
	}

	ll ans = 0;
	f.init();
	for(int i = 1; i < m; ++i) {
		ll c = f.querry(i, i);
		if(!c) continue;
		ans += c*(c-1)/2 - c*c;
		for(int j = i; j < m; j += i) {
			ll c2 = f.querry(j, min(j+i-1, m));
			ans += c*c2*(j/i);
			// if(c2) cerr << i << ' ' << j << ' ' << j+i-1 << ' ' << c << ' ' << c2 << ' ' << j/i << endl;
		}
	}
	cout << ans << endl;

	return 0;
}