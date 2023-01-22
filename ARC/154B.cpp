#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s, t;
	cin >> n >> s >> t;

	vi count(26, 0);
	for(char c : s) ++count[c-'a'];
	for(char c : t) --count[c-'a'];
	for(int c : count) if(c != 0) {
		cout << "-1\n";
		return 0;
	}

	int ans = n;
	for(int sub = (n+1)/2; sub > 0; sub/=2) {
		while(true) {
			int a = ans - sub;
			if(a < 0) break;
			int i = a, j = -1;
			for(; i < n; ++i) {
				while(++j < n && t[j] != s[i]);
				if(j == n) break;
			}
			if(i == n) ans = a;
			else break;
		}
	}
	cout << ans << '\n';

	return 0;
}