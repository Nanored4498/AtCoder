#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,k;
	cin >> n >> k;
	vector<int> Q(n, -1), L(n, -1);
	for(int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		Q[p-1] = i;
	}
	set<int> s;
	for(int i = 0; i < k; ++i) {
		s.insert(Q[i]);
	}
	int ans = *(--s.end()) - *s.begin();
	for(int i = k; i < n; ++i) {
		s.erase(Q[i-k]);
		s.insert(Q[i]);
		ans = min(ans, *(--s.end()) - *s.begin());
	}
	cout << ans << '\n';

	return 0;
}