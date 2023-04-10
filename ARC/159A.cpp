#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<vi> a(N, vi(N));
	for(vi &r : a) for(int &x : r) { cin >> x; if(!x) x = 1e9; }
	int Q; cin >> Q;
	for(int k = 0; k < N; ++k) {
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	while(Q--) {
		ll s, t;
		cin >> s >> t;
		s = (s-1) % N;
		t = (t-1) % N;
		if(a[s][t] == 1e9) cout << "-1\n";
		else cout << a[s][t] << '\n';
	}


	return 0;
}