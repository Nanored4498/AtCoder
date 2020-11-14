#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;
	int m[3] = {0, 0, 0}, k = 0;
	while(N > 0) {
		int d = N%10;
		++ m[d%3];
		++ k;
		N /= 10;
	}
	int mo = (m[1] + 2*m[2])%3;
	int ans;
	if(mo == 0) ans = 0;
	else {
		if(m[mo] > 0) ans = 1;
		else if(m[3-mo] > 1) ans = 2;
		else ans = -1;
	}
	if(ans >= k) ans = -1;
	cout << ans << "\n";

	return 0;
}