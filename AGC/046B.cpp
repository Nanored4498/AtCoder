#include <iostream>

using namespace std;
typedef long long ll;
const int M = 3001;
const ll MOD = 998244353;

int A, B, C, D;
ll dp[M][M];

int main() {
	cin >> A >> B >> C >> D;
	dp[A][B] = 1;
	for(int a = A; a <= C; ++a) {
		for(int b = B+(a==A); b <= D; ++b) {
			if(a > A) dp[a][b] = (dp[a][b] + b*dp[a-1][b]);
			if(b > B) dp[a][b] = (dp[a][b] + a*dp[a][b-1]);
		}
	}
	cout << dp[C][D] << "\n";
	return 0;
}