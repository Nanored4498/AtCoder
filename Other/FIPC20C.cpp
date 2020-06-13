#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vi A(N), B(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	while(K--) {
		for(int i = 0; i < N; ++i) B[i] = 1;
		priority_queue<int> q, q2;
		for(int i = 0; i < N; ++i) {
			B[i] += q.size();
			q.push(-(i+A[i]));
			while(!q.empty() && -q.top()<=i) q.pop();
		}
		for(int i = N-1; i >= 0; --i) {
			B[i] += q2.size();
			q2.push(i-A[i]);
			while(!q2.empty() && q2.top()>=i) q2.pop();
		}
		bool diff = false;
		for(int i = 0; i < N; ++i) if(A[i] != B[i]) diff = true;
		if(!diff) break;
		swap(A, B);
	}
	for(int i = 0; i < N; ++i) cout << A[i] << " \n"[i+1==N];

	return 0;
}