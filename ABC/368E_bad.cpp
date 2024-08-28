#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x0;
	cin >> n >> m >> x0;
	vector<vector<pii>> beg(n);
	vector<pii> end(m);
	for(int i = 0; i < m; ++i) {
		int a, b, s, t;
		cin >> a >> b >> s >> t;
		--a; --b;
		beg[a].emplace_back(s, i);
		end[i] = {b, t};
	}
	for(auto &v : beg) sort(v.begin(), v.end());

	vector<int> x(m, 0);
	priority_queue<pii> Q;
	Q.emplace(x0, 0);
	while(!Q.empty()) {
		auto [v, i] = Q.top();
		x[i] = max(x[i], v);
		Q.pop();
		auto [b, t] = end[i];
		while(!beg[b].empty()) {
			auto [s, j] = beg[b].back();
			if(s < t) break;
			beg[b].pop_back();
			int w = max(0, v - s + t);
			if(w) Q.emplace(w, j);
		}
	}
	for(int i = 1; i < m; ++i) cout << x[i] << ' ';
	cout << endl;

	return 0;
}