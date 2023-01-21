#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	vector<string> s(n);
	for(string &x : s) cin >> x;
	vector<vector<pair<int, ll>>> d(n, vector<pair<int, ll>>(n, {n+1, 0}));
	for(int i = 0; i < n; ++i) {
		d[i][i] = {0, 0};
		for(int j = 0; j < n; ++j) if(s[i][j] == 'Y') d[i][j] = {1, -a[j]};
	}
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], {d[i][k].first + d[k][j].first, d[i][k].second + d[k][j].second});
			}
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		if(d[u][v].first > n) cout << "Impossible\n";
		else cout << d[u][v].first << ' ' << a[u]-d[u][v].second << '\n';
	}

	return 0;
}