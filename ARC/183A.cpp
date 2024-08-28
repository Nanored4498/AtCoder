#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int m = N/2, f = 0;
	if(N&1) {
		f = m+1;
		for(int k = 0; k < K; ++k) cout << f << ' '; 
	}
	if(m) cout << m << ' ';
	for(int i = N; i > 0; --i) if(i != f)
		for(int k = i == m ? 1 : 0; k < K; ++k)
			cout << i << ' ';
	cout << endl;
	return 0;
}