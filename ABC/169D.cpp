#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, res = 0;
	cin >> N;
	for(ll a = 2; a*a <= N; ++a) {
		ll b = a;
		while(N % b == 0) {
			++ res;
			N /= b;
			b *= a;
		}
		while(N % a == 0) N /= a;
	}
	if(N != 1) ++res;
	cout << res << "\n";

	return 0;
}