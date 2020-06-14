#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int X, N;
	cin >> X >> N;
	bool p[220];
	for(int i = 0; i < 220; ++i) p[i] = false;
	for(int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		p[x] = true;
	}
	for(int d = 0; true; ++d) {
		if(!p[X-d]) return cout << X-d << "\n", 0;
		if(!p[X+d]) return cout << X+d << "\n", 0;
	}

	return 0;
}