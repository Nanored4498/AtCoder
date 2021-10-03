#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;
	int ans = 1;
	while(A-- > B) ans *= 32;
	cout << ans << endl;

	return 0;
}