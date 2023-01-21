#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> ab(n);
	for(auto &[a, b] : ab) cin >> a >> b;
	vector<bool> can(x+1, false);
	can[0] = true;
	for(auto [a, b] : ab) {
		for(int i = x-1; i >= 0; --i) if(can[i]) {
			for(int j = 1; j <= b; ++j)
				if(i+j*a <= x)
					can[i+j*a] = true;
		}
	}
	if(can[x]) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}