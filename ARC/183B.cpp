#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n), b(n);
	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;
	if(k == 1) {
		int j = 0;
		for(int i = 0; i < n; ++i) {
			while(j < n && a[j] != b[i]) ++j;
			if(j >= n) {
				cout << "No\n";
				return;
			}
		}
		cout << "Yes\n";
		return;
	}
	if(a == b) {
		cout << "Yes\n";
		return;
	}
	vector<char> seen(n+1, 0);
	for(int x : a) seen[x] = 1;
	for(int x : b) if(!seen[x]) {
		cout << "No\n";
		return;
	}
	seen.assign(n+1, 0);
	for(int i = 0; i < n; ++i) {
		const int x = b[i];
		if(i > k) --seen[b[i-k-1]];
		if(seen[x]) {
			cout << "Yes\n";
			return;
		}
		++ seen[x];
	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		solve();
	}

	return 0;
}