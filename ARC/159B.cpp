#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

template<typename T>
bool isPrime(T x) {
        typedef __uint128_t u128;
        if(x < 2) return false;
        int s = 0;
        T d = x-1;
        for(; !(d&1); d >>= 1) ++s;
        for(T a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
                if(x == a) return true;
                T b = 1;
                for(T e = d; e; e >>= 1, a = (u128)a*a % x)
                        if(e&1) b = (u128)b*a % x;
                if(b == 1) continue;
                bool composite = true;
                for(int r = 0; r < s; ++r, b = (u128)b*b % x)
                        if(b == x-1) {
                                composite = false;
                                break;
                        }
        if(composite) return false;
        }
        return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	while(a >= 1 && b >= 1) {
		ll g = gcd(a, b);
		ll d = abs(b-a);
		if(d == 1) {
			ll m = min(a, b);
			a -= m;
			b -= m;
			ans += m;
		} else if(g > 1 || !isPrime(d)) {
			a = a/g-1;
			b = b/g-1;
			++ ans;
		} else {
			ll r = a % d;
			a -= r;
			b -= r;
			ans += r;
		}
	}
	cout << ans << '\n';

	return 0;
}