#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<vi> g(N);
	while(M--) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int r = 1<<N;
	ll ans = N;
	vector<bool> seen(N*r, false), seen0(r, false);
	vi Q(N), Q2;
	seen0[0] = true; --r;
	for(int i = 0; i < N; ++i) {
		Q[i] = (i<<N) | (1<<i);
		seen0[1<<i] = true; --r;
		seen[Q[i]] = true;
	}
	int len = 1;
	while(r && !Q.empty()) {
		++ len;
		Q2.clear();
		for(const int x : Q) {
			const int i = x>>N;
			const int s = x&((1<<N)-1);
			for(const int j : g[i]) {
				const int s2 = s^(1<<j);
				const int x2 = (j<<N) | s2;
				if(seen[x2]) continue;
				seen[x2] = true;
				if(!seen0[s2]) { seen0[s2] = true; --r; ans += len; }
				Q2.push_back(x2);
			}
		}
		swap(Q, Q2);
	}
	cout << ans << '\n';

	return 0;
}