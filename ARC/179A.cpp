#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n), ans;
	for(int &x : a) cin >> x;
	sort(a.rbegin(), a.rend());
	ll s = 0;
	bool b = s >= k;
	while(!b && !a.empty()) {
		ans.push_back(a.back());
		s += a.back();
		a.pop_back();
		b = s >= k;
	}
	for(int x : a) {
		ans.push_back(x);
		s += x;
		if(s < k) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for(int x : ans) cout << x << ' ';
	cout << endl;

	return 0;
}