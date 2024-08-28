#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

const int MAX = 1e5+5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vi> mv(MAX);
	vi g(MAX, 0);
	for(int i = 2; i < MAX; ++i) {
		for(int j = i+i; j < MAX; j += i)
			mv[j].push_back(i);
		ranges::sort(mv[i], greater<int>{}, [&](int i) { return g[i]; });
		int x = 1;
		while(!mv[i].empty()) {
			if(g[mv[i].back()] < x) mv[i].pop_back();
			else if(g[mv[i].back()] == x) ++x;
			else break;
		}
		g[i] = x;
	}

	int n;
	cin >> n;
	int gg = 0;
	while(n--) {
		int a;
		cin >> a;
		gg ^= g[a];
	}
	if(gg) cout << "Anna\n";
	else cout << "Bruno\n";

	return 0;
}