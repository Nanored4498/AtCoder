#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<int> vl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	ll x = 0, sa = 0, ans = 0, m = 0;
	for(int i = 0; i < N; ++i) {
		ll a;
		cin >> a;
		sa += a;
		m = max(m, sa);
		ans = max(ans, x+m);
		x += sa;
	}
	cout << ans << "\n";

	return 0;
}