#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

vi f(vi &a) {
	if(a == vi(a.size(), a[0])) return vi(1, a[0]);
	vi a2;
	for(int i = 0; i < (int)a.size(); ++i)
		if(a[i] != a[(i+a.size()-1)%a.size()])
			a2.push_back(a[i]);
	return a2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vi a(n), b(n);
		for(int &x : a) cin >> x;
		for(int &x : b) cin >> x;
		vi a2 = f(a), b2 = f(b);
		if(b2.size() > a2.size()) {
			cout << "No\n";
		} else if(b2.size() == n) {
			cout << (a == b ? "Yes\n" : "No\n");
		} else {
			int na = a2.size();
			int nb = b2.size();
			string ans = "No\n";
			for(int i0 = 0; i0 < na; ++i0) if(a2[i0] == b2[0]) {
				int i = i0, j = 1;
				for(; j < nb; ++j) {
					while((i = (i+1)%na) != i0 && a2[i] != b2[j]);
					if(i == i0) break; 
				}
				if(j == nb) {
					ans = "Yes\n";
					break;
				}
			}
			cout << ans;
		}
	}

	return 0;
}