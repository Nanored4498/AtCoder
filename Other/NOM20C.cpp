#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<ll> A(N+1);
	for(int i = 0; i <= N; ++i) cin >> A[i];
	if(N == 0) return cout << (A[0]==1 ? 1 : -1) << endl, 0;
	if(A[0] > 0) return cout << "-1\n", 0;
	vector<ll> ma(N+1);
	ma[0] = 1;
	for(int i = 1; i <= N; ++i) {
		ll m2 = (ma[i-1] <= INT64_MAX/2) ? 2*ma[i-1] : INT64_MAX;
		if(m2 < A[i]) return cout << "-1\n", 0;
		ma[i] = m2 - A[i];
	}
	ll res = ma[N] = A[N];
	for(int i = N-1; i >= 0; --i) {
		ma[i] = min(ma[i], ma[i+1]) + A[i];
		res += ma[i];
	}
	cout << res << "\n";

	return 0;
}