#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

struct UF {
	vector<int> r;
	UF(int n): r(n, -1) {}
	int find(int i) {
		if(r[i] < 0) return i;
		return r[i] = find(r[i]);
	}
	void merge(int i, int j) {
		i = find(i); j = find(j);
		if(i == j) return;
		if(r[i] > r[j]) swap(i, j);
		r[i] += r[j];
		r[j] = i;
	}
	bool isRoot(int i) { return r[i] < 0; }
	int size(int i) { return -r[find(i)]; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m;
	vector<pair<int, int>> e(m);
	vector<bool> x(m, false);
	for(auto &[u, v] : e) {
		cin >> u >> v;
		--u; --v;
	}
	cin >> k;
	while(k--) {
		int i; cin >> i;
		x[i-1] = true;
	}

	UF u(n);
	vi deg(n, 0);
	for(int i = 0; i < m; ++i) if(!x[i]) u.merge(e[i].first, e[i].second);
	for(int i = 0; i < m; ++i) if(x[i]) {
		++ deg[u.find(e[i].first)];
		++ deg[u.find(e[i].second)];
	}
	int odd = 0;
	for(int i = 0; i < n; ++i) if(u.isRoot(i) && (deg[i]&1)) ++ odd;
	if(odd > 2) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}