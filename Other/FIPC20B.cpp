#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll A, V, B, W, T;
	cin >> A >> V >> B >> W >> T;
	if(T*(V-W) >= abs(A-B)) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}