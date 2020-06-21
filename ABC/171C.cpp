#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll N;
	cin >> N;
	string ans = "";
	while(N > 0) {
		-- N;
		ans = char((N%26) + 'a') + ans;
		N /= 26;
	}
	cout << ans << "\n";
	
	return 0;
}