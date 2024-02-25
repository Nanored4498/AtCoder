#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

struct R {
	int a;
	ll l, d, k, c;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<R>> rs(n);
	vector<ll> ans(n, -1);
	while(m--) {
		R r;
		int b;
		cin >> r.l >> r.d >> r.k >> r.c;
		cin >> r.a >> b;
		--r.a;
		rs[b-1].push_back(r);
	}
	priority_queue<pair<ll, int>> Q;
	Q.emplace(ans[n-1] = ll(2e18), n-1);
	while(!Q.empty()) {
		auto [t, b] = Q.top();
		Q.pop();
		if(ans[b] != t) continue;
		for(const auto &[a, l, d, k, c] : rs[b]) {
			if(l+c > t) continue;
			ll i = min(k-1, (t-l-c) / d);
			ll t2 = l + i*d;
			if(t2 <= ans[a]) continue;
			Q.emplace(ans[a] = t2, a);
		}
	}
	ans.pop_back();
	for(ll x : ans)
		if(x < 0) cout << "Unreachable\n";
		else cout << x << '\n';

	return 0;
}