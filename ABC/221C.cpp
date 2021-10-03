#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a;
	cin >> a;
	sort(a.begin(), a.end());
	long long ans = 0;
	do {
		for(int i = 1; i < a.size(); ++i) {
			long long x = stoi(a.substr(0, i));
			long long y = stoi(a.substr(i));
			long long z = x*y;
			ans = max(ans, z);
		}
	} while(next_permutation(a.begin(), a.end()));
	cout << ans << '\n';

	return 0;
}