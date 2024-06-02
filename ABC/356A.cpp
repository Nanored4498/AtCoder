#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	reverse(a.begin()+l-1, a.begin()+r);
	for(int x : a) cout << x << ' ';
	cout << '\n';

	return 0;
}