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

	int n; cin >> n;
	vi a(n); for(int &x : a) cin >> x;
	int mod = accumulate(a.begin(), a.end(), 0)%n;
	if(n&1 && mod != 0) {
		cout << "No\n";
		return 0;
	}
	if(!(n&1) && mod != 0 && mod != (n/2)) {
		cout << "No\n";
		return 0;
	}
	vector<vi> ans;
	if(mod == (n/2)) {
		ans.emplace_back(n);
		for(int i = 0; i < n; ++i) {
			a[i] += i;
			ans.back()[i] = i+1;
		}
	}
	vi o(n); iota(o.begin(), o.end(), 0);
	while(true) {
		sort(o.begin(), o.end(), [&](int i, int j) { return a[i] < a[j]; });
		swap(o[1], o.back());
		int i0 = o[0], i1 = o[1];
		if(a[i0] == a[i1]) break;
		ans.emplace_back(n);
		for(int i = 0; i < n; ++i) ans.back()[o[i]] = i+1;
		swap(ans.back()[i0], ans.back()[i1]);
		for(int i = 0; i < n; ++i) a[i] += ans.back()[i];
		ans.emplace_back(n);
		for(int i = 0; i < n; ++i) ans.back()[o[i]] = n-i;
		for(int i = 0; i < n; ++i) a[i] += ans.back()[i];
	}
	cout << "Yes\n";
	cout << ans.size() << '\n';
	for(vi &a : ans) {
		for(int x : a) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}