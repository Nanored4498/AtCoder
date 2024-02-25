#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <random>
#include <tuple>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

struct Crop { int S, D; };
struct Plan { int k, i, j, s; Plan(int k, int i, int j, int s): k(k), i(i), j(j), s(s) {} };

int T, H, W, K, i0;
vector<Crop> crops;
vector<vi> G;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T >> H >> W >> i0;
	vector<string> hwalls(H-1), vwalls(H);
	for(string &ws : hwalls) cin >> ws;
	for(string &ws : vwalls) cin >> ws;
	cin >> K;
	crops.resize(K);
	for(Crop &c : crops) cin >> c.S >> c.D;

	G.resize(H*W);
	for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) {
		const int k = i + j*H;
		if(i+1 < H && hwalls[i][j] == '0') {
			G[k].push_back(k+1); 
			G[k+1].push_back(k);
		}
		if(j+1 < W && vwalls[i][j] == '0') {
			G[k].push_back(k+H); 
			G[k+H].push_back(k);
		}
	}

	vector<bool> seen(G.size(), false);
	seen[i0] = true;
	vi bfs(1, i0);
	for(int i = 0; i < (int) bfs.size(); ++i) {
		for(int j : G[bfs[i]]) if(!seen[j]) {
			seen[j] = true;
			bfs.push_back(j);
		}
	}

	vector<vi> dp(T+1, vi(T+1, 0));
	vi QT0(crops.size()), T0;
	iota(QT0.begin(), QT0.end(), 0);
	ranges::sort(QT0, less<int>(), [&](int i) { return crops[i].S; });
	for(int t0 = T; t0 > 0; --t0) {
		while(!QT0.empty() && t0 <= crops[QT0.back()].S) {
			T0.push_back(QT0.back());
			QT0.pop_back();
		}
		ranges::sort(T0, less<int>(), [&](int i) { return crops[i].D; });
		const auto cmpL = [&](int i, int j) {
			return crops[i].D - crops[i].S > crops[j].D - crops[j].S;
		};
		priority_queue<int, vi, decltype(cmpL)> rm(cmpL);
		int sc = 0;
		for(int t1 = t0, i = 0; t1 <= T; ++t1) {
			while(i < (int) T0.size() && crops[T0[i]].D <= t1) {
				const int j = T0[i];
				const int lj = crops[j].D - crops[j].S;
				if(rm.size() < bfs.size()) {
					sc += lj;
					rm.push(j);
				} else {
					const int k = rm.top();
					const int lk = crops[k].D - crops[k].S;
					if(lk < lj) {
						sc += lj-lk;
						rm.pop();
						rm.push(j);
					}
				}
				++ i;
			}
			dp[t0][t1] = sc;
		}
	}

	vi DP(T+1, 0), pred(T+1, 1);
	for(int i = 1; i <= T; ++i) {
		DP[i] = dp[1][i];
		for(int j = 2; j <= i; ++j) {
			const int s = DP[j-1] + dp[j][i];
			if(s > DP[i]) {
				DP[i] = s;
				pred[i] = j;
			}
		}
	}

	vector<Plan> sol;
	int t1 = T;
	while(t1) {
		const int t0 = pred[t1];
		vi order;
		for(int i = 0; i < (int) crops.size(); ++i) if(t0 <= crops[i].S && crops[i].D <= t1) order.push_back(i);
		ranges::sort(order, greater<int>(), [&](int i) { return crops[i].D - crops[i].S; });
		const int N = min(bfs.size(), order.size());
		ranges::sort(order.begin(), order.begin() + N, less<int>(), [&](int i) { return crops[i].D; });
		for(int i = 0; i < N; ++i) {
			const int p = bfs[i];
			sol.emplace_back(order[i], p%H, p/H, t0);
		}
		t1 = t0-1;
	}

	mt19937 mt;
	int best_na = 0;
	vector<bool> PATH;
	for(int step = 100; step--;) {
		vector<bool> path(G.size(), false);
		vector<bool> access(G.size(), false);
		vi newAccess(G.size());
		for(int i = 0; i < (int) G.size(); ++i) newAccess[i] = G[i].size();
		int na = 1;
		access[i0] = true;
		for(int j : G[i0]) -- newAccess[j];
		priority_queue<tuple<int, int, int>> PQ;
		PQ.emplace(newAccess[i0], mt(), i0);
		while(!PQ.empty()) {
			auto [n, _, i] = PQ.top();
			PQ.pop();
			if(path[i] || newAccess[i] != n) continue;
			na += n-1;
			path[i] = true;
			for(int j : G[i]) if(!access[j]) {
				access[j] = true;
				for(int k : G[j]) if(--newAccess[k] && access[k]) PQ.emplace(newAccess[k], mt(), k);
				if(newAccess[j]) PQ.emplace(newAccess[j], mt(), j);
			}
		}
		if(na > best_na) {
			best_na = na;
			PATH = move(path);
		}
	}


	int treeScore = 0;
	vector<bool> used(crops.size(), false);
	vector<Plan> sol2;
	for(int loc = 0; loc < (int) G.size(); ++loc) if(!PATH[loc]) {
		vi dp(T+1, 0), nc(T+1, 0), pred(T+1, -1);
		int ld = 0;
		for(int i : T0) if(!used[i]) {
			const auto [s, d] = crops[i];
			for(int d2 = ld+1; d2 <= d; ++d2) {
				dp[d2] = dp[ld];
				nc[d2] = nc[ld];
				pred[d2] = pred[ld];
			}
			ld = d;
			const int x = dp[s-1] + d-s+1;
			const int y = nc[s-1] + 1;
			if(x > dp[d] || (x == dp[d] && y < nc[d])) {
				dp[d] = x;
				nc[d] = y;
				pred[d] = i;
			}
		}
		treeScore += dp[ld];
		while(ld) {
			const int i = pred[ld];
			if(i == -1) break;
			used[i] = true;
			sol2.emplace_back(i, loc%H, loc/H, crops[i].S);
			ld = crops[i].S-1;
		}
	}
	if(treeScore > DP[T]) {
		sol = move(sol2);
	}


	cout << sol.size() << '\n';
	for(const auto &[k, i, j, s] : sol) cout << k+1 << ' ' << i << ' ' << j << ' ' << s << '\n';

	return 0;
}