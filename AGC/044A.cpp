#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, div[3] = {2, 3, 5};
	cin >> T;
	while(T --> 0) {
		ll N, cs[3], D;
		cin >> N >> cs[0] >> cs[1] >> cs[2] >> D;
		priority_queue<pll> q;
		unordered_map<ll, ll> ds;
		q.emplace(0, N);
		ds[N] = 0;
		ds[0] = INT64_MAX;
		while(!q.empty()) {
			ll n = q.top().second;
			ll d = - q.top().first;
			q.pop();
			if(ds[n] < d) continue;
			if(d >= ds[0]) break;
			if(n <= (INT64_MAX-d) / D) ds[0] = min(ds[0], d+n*D);
			for(int i = 0; i < 3; ++i) {
				ll m = n%div[i];
				ll n2 = n/div[i], d2 = d+cs[i]+D*m;
				if(!ds.count(n2) || d2 < ds[n2]) {
					ds[n2] = d2;
					q.emplace(-d2, n2);
				}
				if(m == 0) continue;
				++ n2;
				d2 = d+cs[i]+D*(div[i]-m);
				if(!ds.count(n2) || d2 < ds[n2]) {
					ds[n2] = d2;
					q.emplace(-d2, n2);
				}
			}
		}
		cout << ds[0] << "\n";
	}

	return 0;
}