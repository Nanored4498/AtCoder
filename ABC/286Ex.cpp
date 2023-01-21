#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct pt {
    double x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pii> ps(n);
	for(auto &[x, y] : ps) cin >> x >> y;
	pii s, t;
	cin >> s.first >> s.second;
	cin >> t.first >> t.second;

	vector<pt> a;
	for(auto [x, y] : ps) a.push_back(pt{double(x), double(y)});
	a.push_back(pt{double(s.first), double(s.second)});
	a.push_back(pt{double(t.first), double(t.second)});
	convex_hull(a, true);
	n = a.size();
	int i = 0;
	while(i < n && (abs(a[i].x-s.first) > .1 || abs(a[i].y-s.second) > .1)) ++i;
	int j = 0;
	while(j < n && (abs(a[j].x-t.first) > .1 || abs(a[j].y-t.second) > .1)) ++j;

	if(i == n || j == n) {
		double dx = s.first - t.first;
		double dy = s.second - t.second;
		cout << fixed << setprecision(10) << sqrt(dx*dx+dy*dy) << endl;
		return 0;
	}

	if(i > j) swap(i, j);
	double L = 0., l = 0.;
	for(int k = 0; k < n; ++k) {
		double dx = a[k].x - a[(k+1)%n].x;
		double dy = a[k].y - a[(k+1)%n].y;
		double d = sqrt(dx*dx + dy*dy);
		L += d;
		if(k >= i && k < j) l += d;
	}
	cout << fixed << setprecision(10) << min(l, L-l) << endl;

	return 0;
}