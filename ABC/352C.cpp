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

	int n;
	cin >> n;
	ll m = 0, s = 0;
	while(n--) {
		ll a, b;
		cin >> a >> b;
		m = max(m, b-a);
		s += a;
	}
	cout << s+m << '\n';

	return 0;
}