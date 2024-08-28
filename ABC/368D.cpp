#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;

vector<vi> G;
vi p, d;

void dfs(int i, int j=-1, int e=0) {
	p[i] = j;
	d[i] = e;
	for(int k : G[i]) if(k != j) dfs(k, i, e+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	G.resize(n);
	for(int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	p.resize(n);
	d.resize(n);
	dfs(0);

	int ans = k;
	vector<bool> inQ(n, false);
	priority_queue<pair<int, int>> Q;
	while(k--) {
		int v;
		cin >> v;
		--v;
		inQ[v] = true;
		Q.emplace(d[v], v);
	}
	while(Q.size() > 1) {
		const auto [e, i] = Q.top();
		Q.pop();
		const int j = p[i];
		if(inQ[j]) continue;
		inQ[j] = true;
		Q.emplace(e-1, j);
		++ans;
	}
	cout << ans << endl;

	return 0;
}