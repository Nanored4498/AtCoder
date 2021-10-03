#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S, T;
	cin >> S >> T;
	if(S == T) {
		cout << "Yes\n";
		return 0;
	}
	for(int i = 1; i < S.size(); ++i) {
		swap(S[i-1], S[i]);
		if(S == T) {
			cout << "Yes\n";
			return 0;
		}
		swap(S[i-1], S[i]);
	}
	cout << "No\n";
	return 0;
}