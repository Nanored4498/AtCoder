#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi d;
vector<vi> G;
void dfs(int x, int p) {
	for(int y : G[x]) if(y != p) {
		d[y] = d[x]+1;
		dfs(y, x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	G.resize(N);
	for(int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	d.resize(N);
	d[0] = 0;
	dfs(0, 0);

	while(Q--) {
		int a, b;
		cin >> a >> b;
		int diff = abs(d[b-1] - d[a-1]);
		if(diff&1) cout << "Road\n";
		else cout << "Town\n";
	}

	return 0;
}