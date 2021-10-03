#include <iostream>
#include <algorithm>

#include "../CPHeaders/segment_tree.h"
#include "../CPHeaders/mod_arith.h"

using namespace std;
const int MOD = 998244353;
typedef mint<MOD> mi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(N);
	for(int &x : A) cin >> x;

	vector<pair<int, int>> B(N);
	for(int i = 0; i < N; ++i) B[i] = {A[i], i};
	sort(B.begin(), B.end());
	int c = 0;
	for(int i = 0; i < N; ++i) {
		if(i == 0 || B[i].first != B[i-1].first) ++c;
		A[B[i].second] = c;
	}
	Fenwick<mi> sump(c);
	mi ans = 0;
	mi pi = 1, pii = 1, i2 = inv(mi(2));
	for(int x : A) {
		mi q = sump.querry(x);
		pi *= 2;
		pii *= i2;
		ans += pi * q * i2;
		sump.add(x, pii);
	}
	cout << ans << endl;

	return 0;
}