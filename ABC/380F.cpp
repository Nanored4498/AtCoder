#include <iostream>
#include <array>

using namespace std;

const int MAX_S = 12;
array<int, MAX_S> a;
array<char, 540'000> win = {0};
array<int, MAX_S> p3;
int s;

char f(const int c) {
	if(win[c]) return win[c];
	char n = 0, l = MAX_S;
	int c2 = 0;
	array<char, MAX_S> A;
	for(char i = 0; i < s; ++i) {
		const int x = (c/p3[i]) % 3;
		if(x == 1) {
			A[n++] = i;
			c2 += 2*p3[i];
		} else if(x == 0) A[--l] = i;
		else c2 += p3[i];
	}
	for(char i = 0; i < n; ++i) {
		const char u = A[i];
		const int c3 = c2 - 2*p3[u];
		if(f(c3) == 2) return win[c] = 1;
		for(int j = l; j < MAX_S; ++j) {
			const char v = A[j];
			if(a[v] >= a[u]) continue;
			if(f(c3 + 2*p3[v]) == 2) return win[c] = 1;
		}
	}
	return win[c] = 2;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p3[0] = 1;
	for(int s = 1; s < MAX_S; ++s) p3[s] = p3[s-1]*3;

	int n, m, l;
	cin >> n >> m >> l;
	s = n+m+l;
	for(int i = 0; i < s; ++i) cin >> a[i];
	int c = 0;
	for(int i = 0; i < m; ++i) c = 3*c+2;
	for(int i = 0; i < n; ++i) c = 3*c+1;
	if(f(c) == 1) cout << "Takahashi\n";
	else cout << "Aoki\n";

	return 0;
}