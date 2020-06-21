#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	vi p(N);
	for(int i = 0; i < N; ++i) cin >> p[i];
	sort(p.begin(), p.end());
	int ans = 0;
	for(int i = 0; i < K; ++i) ans += p[i];
	cout << ans << "\n";
	
	return 0;
}