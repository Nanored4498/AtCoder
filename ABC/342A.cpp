#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	vector<int> a(256, 0);
	cin >> s;
	for(char c : s) ++ a[c];
	for(int i = 0; i < s.size(); ++i) if(a[s[i]] == 1) cout << i+1 << endl;

	return 0;
}