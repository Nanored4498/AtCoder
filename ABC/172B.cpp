#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S, T;
	cin >> S >> T;
	int ans = 0, n = S.size();
	for(int i = 0; i < n; ++i) if(S[i] != T[i]) ++ ans;
	cout << ans << endl;
	
	return 0;
}