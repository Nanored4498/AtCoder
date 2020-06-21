#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	map<ll, int> A;
	ll s = 0;
	for(int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		++ A[a];
		s += a;
	}

	int Q;
	cin >> Q;
	while(Q--) {
		int B, C;
		cin >> B >> C;
		int b = A[B];
		s += b*(C-B);
		A[B] -= b;
		A[C] += b;
		cout << s << "\n";
	}

	return 0;
}