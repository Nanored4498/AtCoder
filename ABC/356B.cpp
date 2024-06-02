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

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(int &x : a) cin >> x;
	while(n--) {
		for(int i = 0; i < m; ++i) {
			int x;
			cin >> x;
			a[i] -= x;
		}
	}
	for(int &x : a) {
		if(x > 0) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";

	return 0;
}