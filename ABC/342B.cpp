#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n;
	vector<int> p(n), r(n+1);
	for(int &x : p) cin >> x;
	for(int i = 0; i < n; ++i) r[p[i]] = i;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		if(r[a] < r[b]) cout << a << '\n';
		else cout << b << '\n';
	}

	return 0;
}