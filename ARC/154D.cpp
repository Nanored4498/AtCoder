#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int o = 1;
void sort(vi::iterator a, vi::iterator b) {
	int n = b-a;
	if(n <= 1) return;
	vi::iterator c = a + (n/2);
	sort(a, c);
	sort(c, b);
	vi tmp(n);
	vi::iterator i = a, j = c, k = tmp.begin();
	while(i != c && j != b) {
		cout << "? " << o << ' ' << *i << ' ' << *j << endl;
		string ans;
		cin >> ans;
		if(ans == "Yes") *(k++) = *(j++);
		else *(k++) = *(i++);
	}
	while(i != c) *(k++) = *(i++);
	while(j != b) *(k++) = *(j++);
	k = tmp.begin();
	while(a != b) *(a++) = *(k++);
}

int main() {
	int n; cin >> n;
	for(int i = 2; i <= n; ++i) {
		cout << "? " << o << ' ' << o << ' ' << i << endl;
		string ans;
		cin >> ans;
		if(ans == "Yes") o = i;
	}

	vi Q;
	for(int i = 1; i <= n; ++i) if(i != o) Q.push_back(i);
	sort(Q.begin(), Q.end());
	vi P(n);
	P[o-1] = 1;
	for(int i = 0; i < n-1; ++i) P[Q[i]-1] = i+2;
	cout << '!';
	for(int x : P) cout << ' ' << x;
	cout << endl;

	return 0;
}