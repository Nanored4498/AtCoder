#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	vi a(N);
	for(int i = 0; i < N; ++i) cin >> a[i];
	int x = 0;
	for(int i = 0; i < N; ++i) x ^= a[i];
	for(int i = 0; i < N; ++i) cout << (x^a[i]) << " \n"[i+1==N];

	return 0;
}