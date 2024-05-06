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

	string s, t;
	cin >> s >> t;
	int i = 0;
	for(char c : s) {
		while(t[i] != c) ++i;
		cout << ++i << ' ';
	}
	cout << '\n';

	return 0;
}