#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	vector<vector<int>> G(N+1);
	while(Q--) {
		int l, r;
		cin >> l >> r;
		G[l-1].push_back(r);
		G[r].push_back(l-1);
	}
	vector<bool> seen(N+1, false);
	vector<int> v = {0};
	seen[0] = true;
	while(!v.empty()) {
		int x = v.back();
		v.pop_back();
		for(int y : G[x]) if(!seen[y]) {
			if(y == N) {
				cout << "Yes\n";
				return 0;
			}
			seen[y] = true;
			v.push_back(y);
		}
	}

	cout << "No\n";
	return 0;
}