#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;

	const int M = 2e5+5;
	vector<int> p(M, 0);
	vector<vi> d(M);
	for(int i = 2; i < M; ++i) {
		if(!p[i]) for(int j = i; j < M; j += i) p[j] = i;
		int j = i;
		while(j > 1) {
			int q = p[j], e = 0;
			while(p[j] == q) {
				j /= q;
				++e;
			}
			if(e&1) d[i].push_back(q);
		}
	}

	ll ans = 0;
	map<vi, int> m;
	int z = 0, nz = 0;
	for(int x : a) {
		ans += z;
		if(x == 0) {
			ans += nz;
			++z;
		} else {
			ans += m[d[x]];
			++ m[d[x]];
			++nz;
		}
	}
	cout << ans << endl;

	return 0;
}