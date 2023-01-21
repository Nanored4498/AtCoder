#include <iostream>
#include <vector>

#include "../CPHeaders/chinese.h"

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
	vi m = {4, 9, 5, 7, 11, 13, 17, 19, 23}, A;
	ll i0 = 0;
	for(ll n : m) {
		for(int i = 1; i < n; ++i) A.push_back(i0+i);
		A.push_back(i0);
		i0 += n;
	}
	cout << A.size() << endl;
	for(ll x : A) cout << x+1 << ' ';
	cout << endl;
	
	vi b(108);

	if(true) {
		for(ll &x : b) cin >> x;
	} else {
		int N = 569;
		for(int i = 0; i < 108; ++i) {
			b[i] = i;
			for(int s = 0; s < N; ++s)
				b[i] = A[b[i]];
			++ b[i];
		}
	}

	vi a(m.size());
	i0 = 0;
	for(int i = 0; i < (int)a.size(); ++i) {
		a[i] = (b[i0]-i0-1) % m[i];
		i0 += m[i];
	}
	cout << chineseRM(a, m) << endl;

	return 0;
}