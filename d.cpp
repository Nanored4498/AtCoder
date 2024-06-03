#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
using ll = long long;
using vi = vector<int>;

vector<vi> G;
vector<array<int, 4>> dp;


// 0: without gate without comeback
// 1: without gate with comeback
// 2: with gate without comeback
// 3: with gate with comeback

void f(int i, int p=-1) {
	for(int j : G[i]) if(j != p) f(j, i);

	int min_add_cb = 0;
	for(int j : G[i]) if(j != p) {
		dp[i][0] += 2 + dp[j][1];
		min_add_cb = min(min_add_cb, dp[j][0] - dp[j][1] - 1);
	}
	dp[i][1] = dp[i][0];
	dp[i][0] += min_add_cb;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	G.resize(n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dp.resize(n, {0, 0, 0, 0});
	f(0);

	return 0;
}