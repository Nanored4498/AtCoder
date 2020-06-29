#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	vi A(N), B(M);
	for(int i = 0; i < N; ++i) cin >> A[i];
	for(int i = 0; i < M; ++i) cin >> B[i];
	int t = 0, j = 0;
	while(j < M && t+B[j] <= K) t += B[j++];
	int ans = j;
	for(int i = 0; i < N; ++i) {
		t += A[i];
		while(t > K && j > 0) t -= B[--j]; 
		if(t > K) break;
		ans = max(ans, j+i+1);
	}
	cout << ans << endl;
	
	return 0;
}