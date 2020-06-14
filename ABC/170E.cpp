#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	const int M = 2e5+5;
	vector<priority_queue<pii>> qs(M);
	vi A(N+1), B(N+1);
	for(int i = 1; i <= N; ++i) {
		cin >> A[i] >> B[i];
		qs[B[i]].emplace(A[i], i);
	}
	priority_queue<pii> q;
	for(int i = 1; i < M; ++i) if(!qs[i].empty())
		q.emplace(-qs[i].top().first, i);

	while(Q--) {
		int C, D;
		cin >> C >> D;
		int bc = B[C];
		B[C] = D;
		qs[D].emplace(A[C], C);
		q.emplace(-qs[D].top().first, D);
		while(!qs[bc].empty() && B[qs[bc].top().second] != bc) qs[bc].pop();
		if(!qs[bc].empty()) q.emplace(-qs[bc].top().first, bc);
		while(true) {
			int b = q.top().second;
			int x = - q.top().first;
			if(qs[b].empty()) q.pop();
			else if(B[qs[b].top().second] != b) {
				qs[b].pop();
				if(!qs[b].empty()) q.emplace(-qs[b].top().first, b);
			} else if(qs[b].top().first != x) {
				q.pop();
				q.emplace(-qs[b].top().first, b);
			}
			else break;
		}
		int ans = -q.top().first;
		cout << ans << "\n";
	}

	return 0;
}