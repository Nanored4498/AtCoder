#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'n' && i+1 < n && s[i+1] == 'a') {
			cout << "nya";
			++i;
		} else cout << s[i];
	}
	cout << '\n';

	return 0;
}