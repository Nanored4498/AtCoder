#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, W, K;
	cin >> H >> W >> K;
	pii a, b;
	cin >> a.first >> a.second >> b.first >> b.second;
	-- a.first; -- a.second;
	-- b.first; -- b.second;
	vector<string> c(H);
	vector<set<int>> rs(H), cs(W);
	for(int i = 0; i < H; ++i) {
		cin >> c[i];
		for(int j = 0; j < W; ++j) {
			rs[i].insert(j);
			cs[j].insert(i);
		}
	}

	vector<pii> Q, Q2;
	int ans = 0;
	Q.push_back(a);
	rs[a.first].erase(a.second);
	cs[a.second].erase(a.first);
	while(!Q.empty()) {
		Q2.clear();
		++ans;
		for(const pii &p : Q) {
			int x = p.first, y = p.second;
			auto it = rs[x].lower_bound(y);
			while(it != rs[x].begin()) {
				--it;
				if(*it < y-K || c[x][*it] == '@') { ++it; break; }
				if(x == b.first && *it == b.second) return cout << ans << "\n", 0;
				Q2.emplace_back(x, *it);
				cs[*it].erase(x);
				it = rs[x].erase(it);
			}
			while(it != rs[x].end()) {
				if(*it > y+K || c[x][*it] == '@') break;
				if(x == b.first && *it == b.second) return cout << ans << "\n", 0;
				Q2.emplace_back(x, *it);
				cs[*it].erase(x);
				it = rs[x].erase(it);
			}
			it = cs[y].lower_bound(x);
			while(it != cs[y].begin()) {
				--it;
				if(*it < x-K || c[*it][y] == '@') {	++it; break; }
				if(*it == b.first && y == b.second) return cout << ans << "\n", 0;
				Q2.emplace_back(*it, y);
				rs[*it].erase(y);
				it = cs[y].erase(it);
			}
			while(it != cs[y].end()) {
				if(*it > x+K || c[*it][y] == '@') break;
				if(*it == b.first && y == b.second) return cout << ans << "\n", 0;
				Q2.emplace_back(*it, y);
				rs[*it].erase(y);
				it = cs[y].erase(it);
			}
		}
		swap(Q, Q2);
	}
	cout << "-1\n";

	return 0;
}