#include <iostream>
#include <vector>

#include "../CPHeaders/mod_arith.h"

using namespace std;
typedef vector<int> vi;
const int MOD = 1e9+7;
typedef mint<MOD> mi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vi H(N);
	for(int &x : H) cin >> x;
	vector<mi> ans(1, 1);
	for(int i = 1; i < N; ++i) {
		vector<mi> s(i+1), a(i+1);
		s[0] = 0;
		for(int j = 0; j < i; ++j) s[j+1] = s[j] + ans[j];
		for(int j = 0; j <= i; ++j) {
			if(H[i] > H[i-1]) a[j] = s[j];
			else if(H[i] < H[i-1]) a[j] = s.back() - s[j];
			else a[j] = s.back();
		}
		ans = a;
	}
	mi A = 0;
	for(mi &x : ans) A += x;
	cout << A << endl;

	return 0;
}