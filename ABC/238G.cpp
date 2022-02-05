#include <iostream>
#include <vector>
#include <random>
#include <array>

using namespace std;
typedef unsigned long long ull;
const int MAX_A = 1e6+5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int np = 0;
	vector<int> d(MAX_A, 0);
	for(int i = 2; i < MAX_A; ++i) if(d[i] == 0) {
		d[i] = -(np++);
		for(int j = i+i; j < MAX_A; j += i) d[j] = i;
	}

	vector<array<ull, 2>> h(np, {0, 0});
	vector<int> t(np, 0);
	mt19937 rd;
	uniform_int_distribution<ull> D(0, 1ull<<63);
	for(auto &a : h) {
		for(ull &x : a) while(!x) x = D(rd);
		a[1] ^= a[0];
	}

	int N, Q;
	cin >> N >> Q;
	vector<ull> A(N, 0), SA(N+1, 0);
	for(ull &a : A) {
		int x;
		cin >> x;
		while(x > 1) {
			int p = -d[x];
			if(p >= 0) x = 1;
			else {
				x /= -p;
				p = -d[-p];
			}
			a ^= t[p] < 2 ? h[p][t[p]] : h[p][0]^h[p][1];
			t[p] = (t[p]+1) % 3; 
		}
	}
	for(int i = 0; i < N; ++i) SA[i+1] = SA[i] ^ A[i];

	while(Q--) {
		int l, r;
		cin >> l >> r;
		ull s = SA[r] ^ SA[l-1];
		cout << (s == 0 ? "Yes" : "No") << '\n';
	}

	return 0;
}