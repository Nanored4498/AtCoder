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

	ll N, A, res = 1;
	cin >> N;
	const ll m = 1e18;
	while(N --> 0) {
		cin >> A;
		if(res == 0 || A == 0) res = 0;
		else if(res < 0 || A > m/res) res = -1;
		else res *= A;
	}
	cout << res << "\n";

	return 0;
}