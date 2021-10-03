#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	vector<pair<int, int>> a;
	cin >> N;
	a.reserve(2*N);
	for(int i = 0; i < N; ++i) {
		int A, B;
		cin >> A >> B;
		a.emplace_back(A, +1);
		a.emplace_back(A+B, -1);
	}
	sort(a.begin(), a.end());
	vector<int> ans(N+1, 0);
	int k = 0, s = 1, i = 0;
	while(i < a.size()) {
		ans[k] += a[i].first - s;
		s = a[i].first;
		while(a[i].first == s)
			k += a[i++].second;
	}
	for(int i = 1; i <= N; ++i) cout << ans[i] << ' ';
	cout << endl;

	return 0;
}