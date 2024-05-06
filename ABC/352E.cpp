#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

struct UF {
	vector<int> r;
	UF(int n): r(n, -1) {}
	int find(int i) {
		if(r[i] < 0) return i;
		return r[i] = find(r[i]);
	}
	void merge(int i, int j) {
		i = find(i); j = find(j);
		if(i == j) return;
		if(r[i] > r[j]) swap(i, j);
		r[i] += r[j];
		r[j] = i;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	UF u(n);
	vector<pair<ll, vi>> op(m);
	for(auto &[c, a] : op) {
		int k;
		cin >> k >> c;
		a.resize(k);
		for(int &x : a) {
			cin >> x;
			--x;
		}
	}

	sort(op.begin(), op.end());
	ll ans = 0;
	int e = 0;
	for(const auto &[c, a] : op) {
		for(int i = 1; i < (int)a.size(); ++i) {
			int x = u.find(a[i-1]);
			int y = u.find(a[i]);
			if(x != y) {
				u.merge(x, y);
				ans += c;
				++e;
			}
		}
	}

	if(e == n-1) {
		cout << ans << '\n';
	} else cout << "-1\n";

	return 0;
}