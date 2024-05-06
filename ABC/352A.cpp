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

	int n, x, y, z;
	cin >> n >> x >> y >> z;
	if(x > y) swap(x, y);
	if(x <= z && z <= y) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}