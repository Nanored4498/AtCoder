#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vi p(N), q(N), r(N);
	for(int &x : p) cin >> x;
	for(int &x : q) cin >> x;
	for(int i = 0; i < N; ++i) r[p[i]-1] = q[i]-1;
	vector<vi> dp(K+1, vi(N+1, 0)), dp2(K+1, vi(N+1, 0));
	dp[0][N] = 1;
	for(int i = 0; i < N; ++i) {
		for(int k = 0; k <= K; ++k) {
			for(int l = 0; l <= N; ++l) {
				int l2 = min(l, r[i]);
				dp2[k][l2] = (dp2[k][l2] + dp[k][l]) % MOD;
				if(k < K && l > r[i]) dp2[k+1][l] = (dp2[k+1][l] + dp[k][l]) % MOD;
				dp[k][l] = 0;
			}
		}
		swap(dp, dp2);
	}
	int ans = 0;
	for(int l = 0; l <= N; ++l) ans = (ans + dp[K][l]) % MOD;
	cout << ans << endl;

	return 0;
}