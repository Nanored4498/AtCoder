#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	const int M = 1e6+5;
	cin >> N;
	vi count(M, 0);
	vector<bool> div(M, false);
	for(int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		++ count[x];
	}
	int ans = 0;
	for(int i = 1; i < M; ++i) {
		if(div[i] || count[i] == 0) continue;
		if(count[i] == 1) ++ ans;
		for(int j = 2*i; j < M; j += i) div[j] = true;
	}
	cout << ans << "\n";

	return 0;
}