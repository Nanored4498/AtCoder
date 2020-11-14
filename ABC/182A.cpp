#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;
	int ans = 2*A+100 - B;
	cout << ans << "\n";

	return 0;
}