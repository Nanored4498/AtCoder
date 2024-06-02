#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

template<typename T>
struct Fenwick {
	#define LSB(i) ((i)&(-(i)))
	vector<T> v;

	Fenwick() = default;
	Fenwick(int n): v(n+1, 0) {}

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

	int q;
	ll k;
	cin >> q >> k;
	vector<ll> vals;
	vector<pair<char, ll>> qs(q);
	for(auto &[t, x] : qs) {
		cin >> t >> x;
		vals.push_back(x);
	}
	vals.push_back(-1);
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	const int M = vals.size();

	set<int> S;
	Fenwick<int> A(M), B(M);
	for(const auto &[t, x0] : qs) {
		int x = lower_bound(vals.begin(), vals.end(), x0) - vals.begin();
		if(t == '1') {
			auto it = S.lower_bound(x);
			if(it == S.end() || *it != x) { // add
				it = S.emplace_hint(it, x);
				auto it2 = it; ++it2;
				A.add(x, 1);
				if(it2 != S.end() && vals[*it2]-vals[x] <= k) B.add(x, 1);
				if(it != S.begin()) {
					it2 = it; --it2;
					if(vals[x]-vals[*it2] <= k) B.set(*it2, 1);
				}
			} else { // remove
				A.add(x, -1);
				B.set(x, 0);
				it = S.erase(it);
				if(it != S.begin() && it != S.end()) {
					auto it2 = it; --it2;
					if(vals[*it]-vals[*it2] > k) B.set(*it2, 0);
				}
			}
		} else { // querry
			int z = x;
			for(int add = (M-x)/2; add > 0; add /= 2) {
				while(z+add < M && A.querry(x, z+add) == B.querry(x, z+add-1)+1)
					z += add;
			}
			int y = x;
			for(int add = x/2; add > 0; add /= 2) {
				while(y-add > 0 && A.querry(y-add, x) == B.querry(y-add, x-1)+1)
					y -= add;
			}
			cout << A.querry(y, z) << '\n';
		}
	}


	return 0;
}