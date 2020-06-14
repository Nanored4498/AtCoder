#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int X, Y;
	cin >> X >> Y;
	if((Y&1) == 0 && 2*X <= Y && Y <= 4*X) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}