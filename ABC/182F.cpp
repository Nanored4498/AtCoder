#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int N;
ll A[51];
ll X;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X;
	for(int i = 0; i < N; ++i) cin >> A[i];
	A[N] = 2 * (max(A[N-1], X) / A[N-1] + 1) * A[N-1];
	
	map<ll, ll> m, m2;
	m[X] = 1;
	for(int i = N-1; i >= 0; --i) {
		ll b = A[i+1] / A[i];
		m2.clear();
		for(const auto &p : m) {
			ll d = p.first / A[i];
			ll r = p.first - d*A[i];
			if(-b < d && d < b) m2[r] += p.second;
			if(r == 0) continue;
			if(r < 0) {
				r += A[i];
				-- d;
			} else {
				r -= A[i];
				++ d;
			}
			if(-b < d && d < b) m2[r] += p.second;
		}
		swap(m, m2);
	}
	cout << m[0] << "\n";

	return 0;
}