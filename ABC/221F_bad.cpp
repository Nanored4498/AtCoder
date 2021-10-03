#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;

vector<vector<int>> G;
vector<pii> f(int i, int r=-1) {
	vector<pii> ans;
	for(int j : G[i]) if(j != r) {
		vector<pii> a = f(j, i);
		if(a.empty()) ans.emplace_back(1, 1);
		else {
			pii p = {0, 0};
			for(const auto &[l, c] : a) {
				if(l > p.first) p = {l, c};
				else if(l == p.first) p.second += c;
			}
			++ p.first;
			ans.push_back(p);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	if(N == 2) {
		cout << "1\n";
		return 0;
	}
	G.resize(N+1);
	for(int i = 1; i < N; ++i) {
		int u, v; 
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int r = 1;
	while(G[r].size() == 1) ++r;
	vector<pii> a = f(r);
	sort(a.rbegin(), a.rend());
	int c = 1;
	while(c+1 < a.size() && a[c+1].first == a[1].first) ++ c;
	if(a[0].first != a[1].first) {
		int ans = 0;
		for(int i = 1; i <= c; ++i) ans += a[i].second;
		ans = (ll(ans) * ll(a[0].second)) % ll(MOD);
		cout << ans << endl;
	} else {
		int ans = 1, s = 0;
		for(int i = 0; i <= c; ++i) {
			ans = (ll(a[i].second+1) * ll(ans)) % ll(MOD);
			s += a[i].second;
		}
		ans = (ll(ans) + ll(MOD - 1 - s)) % ll(MOD);
		cout << ans << endl;
	}

	return 0;
}