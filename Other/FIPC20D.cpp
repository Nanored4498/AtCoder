#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const int MW = 1e5+1;
const int MN = (1<<18) + 1;

vi dp[513];
int V[MN], W[MN];

int f(int v, int L) {
	if(v <= 512) return dp[v][L];
	int ans = f(v/2, L);
	if(W[v] <= L) ans = max(ans, V[v]+f(v/2, L-W[v]));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) cin >> V[i] >> W[i];

	dp[0] = vi(MW, 0);
	for(int i = 1; i <= min(N, 512); ++i) {
		dp[i] = vi(MW);
		int j = i/2;
		for(int w = 0; w < MW; ++w) dp[i][w] = dp[j][w];
		for(int w = W[i]; w < MW; ++w) dp[i][w] = max(dp[i][w], V[i]+dp[j][w-W[i]]);
	}

	int Q;
	cin >> Q;
	while(Q--) {
		int v, L;
		cin >> v >> L;
		cout << f(v, L) << "\n";
	}

	return 0;
}