#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) {
		ll a, s;
		cin >> a >> s;
		ll b = a+a;
		if(b > s || (s-b)&a) cout << "No\n";
		else cout << "Yes\n";
	}

	return 0;
}