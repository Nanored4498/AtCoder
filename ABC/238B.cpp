#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	int x = 0;
	for(int &y : A) {
		cin >> y;
		x = y = (y+x)%360;
	}
	sort(A.begin(), A.end());
	int ans = max(360-A.back(), A[0]);
	for(int i = 1; i < N; ++i) ans = max(ans, A[i]-A[i-1]);
	cout << ans << endl;
	return 0;
}