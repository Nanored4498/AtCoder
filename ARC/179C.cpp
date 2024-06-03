#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	int start = 1;
	while(start < n) start *= 2;
	vector<pair<int, int>> v(2*start, {0, 0});
	for(int i = 0; i < n; ++i) v[start+i] = {i+1, i+1};

	map<pair<int, int>, int> qs;
	const auto QQ = [&](int i, int j) {
		if(qs.count({i, j})) return qs[{i, j}];
		int Q;
		cout << "? " << i << ' ' << j << endl;
		cin >> Q;
		if(Q == -1) exit(0);
		qs[{i, j}] = Q;
		return Q;
	};

	const auto f = [&](int i) {
		int j = 2*i;
		int k = 2*i+1;
		if(v[j].first == 0) v[i] = v[k];
		else if(v[k].first == 0) v[i] = v[j];
		else {
			int Q = QQ(v[j].first, v[k].first);
			if(Q == 1) v[i].first = v[j].first;
			else v[i].first = v[k].first;
			Q = QQ(v[j].second, v[k].second);
			if(Q == 1) v[i].second = v[k].second;
			else v[i].second = v[j].second;
		}
	};
	for(int i = start-1; i > 0; --i) f(i);

	while(v[1].first != v[1].second) {
		auto [i, j] = v[1];
		cout << "+ " << i << ' ' << j << endl;
		int k; cin >> k;
		if(k == -1) exit(0);
		int x = start;
		while(v[x].first != i) ++x;
		v[x] = {0, 0};
		x = start;
		while(v[x].first != j) ++x;
		v[x] = {k, k};
		for(int i = start-1; i > 0; --i) f(i);
	}

	cout << "!" << endl;

	return 0;
}