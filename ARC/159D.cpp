#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<int, pair<int, int>> m;
	int n; cin >> n;
	while(n--) {
		int l, r;
		cin >> l >> r;
		auto it = m.upper_bound(l);
		if(it == m.begin()) {
			it = m.emplace_hint(it, l, make_pair(1, r));
		} else {
			-- it;
			if(it->second.second >= r) continue;
			if(it->second.second >= l-1) it->second.second = r;
			else {
				int x = it->second.first + it->second.second - it->first;
				it = m.emplace_hint(++it, l, make_pair(x+1, r));
			}
		}
		int s = it->second.first + it->second.second - it->first;
		++ it;
		while(it != m.end()) {
			if(s < it->second.first) break;
			if(s >= it->second.first + it->second.second - it->first) it = m.erase(it);
			else {
				auto x = m.extract(it);
				x.key() += s+1 - x.mapped().first;
				x.mapped().first = s+1;
				m.insert(move(x));
			}
		}
	}

	auto it = --m.end();
	cout << it->second.first + it->second.second - it->first << endl;

	return 0;
}