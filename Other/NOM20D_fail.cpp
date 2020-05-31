#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MOD 1000000009

int P[5001], p[5001], s[5001];

int find(int i) {
	if(p[i] == i) return i;
	p[i] = find(p[i]);
	return p[i];
}

void merge(int i, int j) {
	int ri = find(i), rj = find(j);
	if(ri == rj) return;
	if(s[ri] < s[rj]) swap(ri, rj);
	p[rj] = ri;
	s[ri] += s[rj];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> P[i];
		p[i] = i;
		s[i] = 1;
	}
	ll K = 0;
	vector<ll> ks(N+1, 0);
	for(int i = 1; i <= N; ++i) if(P[i] > 0) merge(i, P[i]);
	for(int i = 1; i <= N; ++i) if(P[i] < 0) {
		++ ks[find(i)];
		++ K;
	}
	ll res = 0, cases = 1, add2 = 0;
	for(int k = 0; k < K; ++k) cases = (cases * (N-1)) % MOD;
	res = (cases * (N-1)) % MOD;
	for(int i = 1; i <= N; ++i) if(find(i) == i) {
		cerr << i << " " << s[i] << " "  << ks[i] << endl;
		if(s[i] < N) {
			ll a = 1;
			for(int j = 0; j < ks[i]; ++j) a = (a * (s[i]-1)) % MOD;
			for(int j = 0; j < K-ks[i]; ++j) a = (a * (N-s[i]-1)) % MOD;
			res = (res + MOD - a) % MOD;
		}
	}
	cout << res << endl;

	return 0;
}