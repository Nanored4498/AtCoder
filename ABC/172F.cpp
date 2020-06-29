#include <iostream>

using namespace std;
typedef long long ll;

ll f(ll a, ll b, ll c) {
	ll x = a^b^c;
	if(x == 0) return 0;
	ll p = 1;
	while((p<<1) <= x) p <<= 1;
	ll da, db = p - (b&(p-1));
	if(a&p) da = 1 + (a&(p-1));
	else if(p < a) {
		ll p2 = p<<1;
		while(!(a&p2)) p2 <<= 1;
		da = 1 + (a&(p2-1));
	} else da = -1;
	if(da == a) da = -1;
	if(da == -1) {
		if(db >= a) return -1;
		ll ans = f(a-db, b+db, c);
		if(ans < 0) return -1;
		else return ans + db;
	} else {
		if(da > db) swap(da, db);
		ll ans = f(a-da, b+da, c);
		if(ans < 0 || ans+da >= db) return -1;
		else return ans+da;
	}
}

int main() {
	int N;
	ll a, b, c=0, x;
	cin >> N >> a >> b;
	for(int i = 0; i < N-2; ++i) {
		cin >> x;
		c ^= x;
	}
	cout << f(a, b, c) << endl;
	return 0;
}