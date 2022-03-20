#include <iostream>
#include <vector>
#include <array>

using namespace std;
typedef vector<int> vi;
const int MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K, S, T, X;
	cin >> N >> M >> K >> S >> T >> X;
	vector<vi> g(N+1);
	while(M--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<array<int, 2>> count(N+1, {0,0}), count2;
	count[S][0] = 1;
	while(K--) {
		count2.assign(N+1, {0,0});
		for(int i = 1; i <= N; ++i)
			for(int j : g[i]) for(int p : {0,1})
				count2[j][p^(i==X)] = (count2[j][p^(i==X)] + count[i][p]) % MOD;
		swap(count, count2);
	}
	cout << count[T][0] << endl;

	return 0;
}