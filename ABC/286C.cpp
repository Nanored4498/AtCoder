#include <iostream>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	ll a, b;
	string s;
	cin >> n >> a >> b >> s;
	ll ans = n*b;
	for(int k = 0; k < n; ++k) {
		ll p = k*a;
		for(int i = 0; i < n/2; ++i)
			if(s[(i+k)%n] != s[(n-1-i+k)%n])
				p += b;
		ans = min(ans, p);
	}
	cout << ans << '\n';

	return 0;
}