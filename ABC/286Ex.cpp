#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#include "../../CPHeaders/geom.h"
#include "../../CPHeaders/convex_hull.h"

using namespace std;
using pt = Point<long long>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pt> ps(n);
	for(pt &p : ps) cin >> p;
	pt s, t;
	cin >> s >> t;
	ps.push_back(s);
	ps.push_back(t);

	vector<pt> ch = convex_hull(ps);
	n = ch.size();
	int i = 0; while(i < n && ch[i] != s) ++i;
	int j = 0; while(j < n && ch[j] != t) ++j;
	if(i == n || j == n) {
		cerr << i << ' ' << j << ' ' << n << endl;
		cout << fixed << setprecision(10) << sqrt(norm2(t-s)) << endl;
		return 0;
	}

	if(i > j) swap(i, j);
	double L = 0., l = 0.;
	for(int k = 0; k < n; ++k) {
		double d = sqrt(norm2(ch[k] - ch[(k+1)%n]));
		L += d;
		if(k >= i && k < j) l += d;
	}
	cout << fixed << setprecision(10) << min(l, L-l) << endl;

	return 0;
}