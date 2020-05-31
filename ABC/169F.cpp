#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define MOD 998244353

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, S;
	cin >> N >> S;
	vi A(N+1);
	for(int i = 1; i <= N; ++i) cin >> A[i];
	vector<vi> d(N+1, vi(S+1));
	for(int i = 0; i <= S; ++i) d[0][i] = 0;
	d[0][0] = 1;
	for(int i = 1; i <= N; ++i) {
		for(int s = 0; s <= S; ++s) {
			d[i][s] = (2*d[i-1][s]) % MOD;
			if(s-A[i] >= 0) d[i][s] = (d[i][s] + d[i-1][s-A[i]]) % MOD;
		}
	}
	cout << d[N][S] << endl;

	return 0;
}