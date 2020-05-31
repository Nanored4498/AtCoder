#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H1, M1, H2, M2, K;
	cin >> H1 >> M1 >> H2 >> M2 >> K;
	int res = 60*(H2-H1) + (M2-M1) - K;
	cout << res << endl;

	return 0;
}