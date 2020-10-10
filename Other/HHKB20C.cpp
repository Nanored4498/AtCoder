#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

bool seen[200002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int ans = 0;
	for(int i = 0; i < N; ++i) {
		int p;
		cin >> p;
		seen[p] = true;
		while(seen[ans]) ++ ans;
		cout << ans << "\n";
	}

	return 0;
}