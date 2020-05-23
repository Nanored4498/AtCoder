#include <iostream>
#include <queue>

using namespace std;

struct Comp {
	bool operator()(const string &a, const string &b) { return a.size() > b.size(); }
};

int main() {

	priority_queue<string, vector<string>, Comp> q;
	int ans, L0 = 128, L = 0;
	string alphabet;
	for(char c = 'a'; c <= 'z'; ++c) alphabet += c;
	for(char c = 'A'; c <= 'Z'; ++c) alphabet += c;
	for(char c = '0'; c <= '9'; ++c) alphabet += c;
	for(char c : alphabet) {
		cout << "? " << string(L0, c) << endl;
		cin >> ans;
		if(ans < L0) q.push(string(L0-ans, c));
		L += L0 - ans;
	}
	while(q.size() > 1) {
		string a = q.top(); q.pop();
		string b = q.top(); q.pop();
		string c;
		int i = 0, j = 0;
		while(i < a.size() && j < b.size()) {
			string test = c + a[i] + b.substr(j);
			cout << "? " << test << endl;
			cin >> ans;
			if(L-ans == test.size()) c += a[i++];
			else c += b[j++];
		}
		c += a.substr(i) + b.substr(j);
		q.emplace(c);
	}
	cout << "! " << q.top() << endl;

	return 0;
}