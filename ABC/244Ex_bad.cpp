#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

struct Comp {
	bool operator()(const pll &a, const pll &b) const {
		if(a.first > 0) {
			if(b.first > 0) return a.second*b.first < b.second*a.first;
			return true;
		}
		if(a.first < 0) {
			if(b.first > 0) return false;
			if(b.first < 0) return a.second*b.first < b.second*a.first;
			return b.second < 0;
		}
		if(b.first > 0) return false;
		if(b.first < 0) return a.second > 0;
		if(b.second > 0) return false;
		return a.second > 0;
	}
};

inline ll dot(const pll &a, const pll &b) {
	return a.first*b.first + a.second*b.second;
}

inline bool turnRight(const pll &a, const pll &b, const pll &c) {
	return (a.second-b.second)*(c.first-b.first) + (b.first-a.first)*(c.second-b.second) > 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int Q;
	cin >> Q;
	bool zero = false;
	set<pll, Comp> c;
	while(Q--) {
		pll x, a;
		cin >> x.first >> x.second >> a.first >> a.second;
		if(x == make_pair(0LL,0LL)) zero = true;
		else if(c.empty()) c.insert(x);
		else {
			auto it = c.lower_bound(x);
			if(it != c.end() && !Comp()(x, *it)) {
				if(abs(x.first) > abs(it->first) || abs(x.second) > abs(it->second))
					c.emplace_hint(c.erase(it), x);
			} else if(c.size() <= 2) {
				c.emplace_hint(it, x);
			} else {
				it = c.emplace_hint(it, x);
				auto it0 = it, it2 = it;
				if(it0 == c.begin()) it0 = c.end();
				-- it0;
				++ it2;
				if(it2 == c.end()) it2 = c.begin();
				if(turnRight(*it0, x, *it2)) {
					while(c.size() > 2) {
						it = c.find(x);
						// Get neighbors
						it0 = it, it2 = it;
						if(it0 == c.begin()) it0 = c.end();
						-- it0;
						++ it2;
						if(it2 == c.end()) it2 = c.begin();
						// pred of it0
						auto it3 = it0;
						if(it3 == c.begin()) it3 = c.end();
						-- it3;
						if(!turnRight(*it3, *it0, x)) {
							c.erase(it0);
							continue;
						}
						// succ of it2
						it3 = it2;
						++ it3;
						if(it3 == c.end()) it3 = c.begin();
						if(!turnRight(x, *it2, *it3)) {
							c.erase(it2);
							continue;
						}
						// Good
						break;
					}
				} else c.erase(it);
			}
		}
		// for(auto [x, y] : c) cerr << "(" << x << ", " << y << ") "; cerr << endl;
		ll ans = zero ? 0LL : numeric_limits<ll>::min();
		if(c.size() > 1) {
			auto it = c.lower_bound(a);
			if(it == c.end()) it = c.begin();
			// cerr << "COMP " << a.first << ' ' << a.second << ' ' << it->first << ' ' << it->second << endl;
			ans = max(ans, dot(a, *it));
			if(it == c.begin()) it = c.end();
			-- it;
			// cerr << "COMP " << a.first << ' ' << a.second << ' ' << it->first << ' ' << it->second << endl;
			ans = max(ans, dot(a, *it));
		} else if(c.size()==1) {
			ans = max(ans, dot(a, *c.begin()));
		}
		cout << ans << '\n';
	}

	return 0;
}