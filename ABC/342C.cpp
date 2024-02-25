#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	string s;
	cin >> n >> s >> q;
	vector<char> nc(256, -1);
	for(char c = 'a'; c <= 'z'; ++c) nc[c] = c;
	while(q--) {
		char c, d;
		cin >> c >> d;
		for(char a = 'a'; a <= 'z'; ++a)
			if(nc[a] == c)
				nc[a] = d;
	}
	for(char &c : s) c = nc[c];
	cout << s << endl;
	
	return 0;
}