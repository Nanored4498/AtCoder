#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p, q, r, s;
	cin >> n >> p >> q >> r >> s;
	--p; --q; --r; --s;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	for(int i = 0; i < n; ++i) {
		if(p <= i && i <= q) cout << a[i-p+r];
		else if(r <= i && i <= s) cout << a[i-r+p];
		else cout << a[i];
		cout << ' ';
	}
	cout << '\n';

	return 0;
}