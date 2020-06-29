#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	int N;
	cin >> N;
	vi ps(N+1, 0);
	ps[1] = 1;
	ll ans = 1;
	for(int i = 2; i <= N; ++i) {
		if(!ps[i]) {
			for(int j = i; j <= N; j += i) ps[j] = i;
			ps[i] = 2;
		} else {
			int p = ps[i];
			int j = i/p, c=1;
			while(j%p == 0) {
				++ c;
				j /= p;
			}
			ps[i] = ps[j] * (1+c);
		}
		ans += 1LL * ps[i] * i;
	}
	cout << ans << endl;
	return 0;
}