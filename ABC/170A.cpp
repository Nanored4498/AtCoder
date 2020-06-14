#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x;
	for(int i = 0; i < 5; ++i) {
		cin >> x;
		if(x == 0) return cout << i+1 << "\n", 0;
	}

	return 0;
}