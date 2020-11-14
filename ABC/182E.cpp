#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<int> vl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, W, N, M;
	cin >> H >> W >> N >> M;

	vector<vector<pair<int, bool>>> rows(H+1), cols(W+1);
	int a, b;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		rows[a].emplace_back(b, true);
		cols[b].emplace_back(a, true);
	}
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		rows[a].emplace_back(b, false);
		cols[b].emplace_back(a, false);
	}

	vector<vector<bool>> light(H+1, vector<bool>(W+1, false));
	for(int i = 1; i <= H; ++i) {
		rows[i].emplace_back(W+1, false);
		sort(rows[i].begin(), rows[i].end());
		int last = 0;
		bool bulb = false;
		for(const auto &o : rows[i]) {
			if(o.second) bulb = true;
			else {
				if(bulb) for(int x = last+1; x < o.first; ++x) light[i][x] = true;
				last = o.first;
				bulb = false;
			}
		}
	}
	for(int i = 1; i <= W; ++i) {
		cols[i].emplace_back(H+1, false);
		sort(cols[i].begin(), cols[i].end());
		int last = 0;
		bool bulb = false;
		for(const auto &o : cols[i]) {
			if(o.second) bulb = true;
			else {
				if(bulb) for(int x = last+1; x < o.first; ++x) light[x][i] = true;
				last = o.first;
				bulb = false;
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= H; ++i) {
		for(int j = 1; j <= W; ++j) {
			if(light[i][j]) ++ ans;
			// cerr << (light[i][j] ? 'o' : 'x');
		}
		// cerr << "\n";
	}
	cout << ans << "\n";

	return 0;
}