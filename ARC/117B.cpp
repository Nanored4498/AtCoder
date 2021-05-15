#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vl A(N+1);
	A[0] = 0;
	for(int i = 1; i <= N; ++i) cin >> A[i];
	sort(A.begin(), A.end());
	ll ans = 1;
	for(int i = 0; i < N; ++i) ans = (ans * (A[i+1] - A[i] + 1)) % MOD;
	cout << ans << '\n';

	return 0;
}