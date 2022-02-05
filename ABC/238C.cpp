#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll ans = 0;
void f(ll a, ll b) {
	a %= MOD;
	b %= MOD;
	ans = (ans + (b*(b+1))/2 - (a*(a-1))/2)%MOD;
	ans = (ans - (b-a+1)*(a-1))%MOD;
	if(ans < 0) ans += MOD;
}

int main() {
	ll N;
	cin >> N;
	ll M = 10;
	while(M <= N) {
		f(M/10, M-1);
		M *= 10;
	}
	f(M/10, N);
	cout << ans << endl;
	return 0;
}