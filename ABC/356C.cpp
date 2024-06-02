#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>
#include <cstdint>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> ok(1<<n, true);
	while(m--) {
		uint32_t a = 0;
		int c;
		char r;
		cin >> c;
		while(c--) {
			int i;
			cin >> i;
			--i;
			a |= 1<<i;
		}
		cin >> r;
		for(uint32_t x = 0; x < (1<<n); ++x) {
			int g = popcount(x&a);
			if(g >= k && r == 'x') ok[x] = false;
			if(g < k && r == 'o') ok[x] = false;
		}
	}
	int ans = 0;
	for(bool x : ok) if(x) ++ans;
	cout << ans << '\n';

	return 0;
}