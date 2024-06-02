#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;
using ll = long long;
using vi = vector<int>;

template<typename T>
struct Point {
	using Vec = Point;
	T x, y;
	Point()=default;
	Point(T x, T y): x(x), y(y) {}

	Point operator+(const Point &p) const { return {x+p.x, y+p.y}; }
	Point operator-(const Point &p) const { return {x-p.x, y-p.y}; }
	Point operator+=(const Point &p) { x += p.x; y += p.y; return *this; }
	Point operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
	Point operator*(T a) const { return {x*a, y*a}; }
	Point operator/(T a) const { return {x/a, y/a}; }
	Point& operator*=(T a) { x *= a; y *= a; return *this; }
	Point& operator/=(T a) { x /= a; y /= a; return *this; }
	friend Point operator*(T a, const Point &p) { return {a*p.x, a*p.y}; }
	friend istream& operator>>(istream &in, Point &p) { return in >> p.x >> p.y; }

	bool operator==(const Point &p) { return x == p.x && y == p.y; }
	bool operator!=(const Point &p) { return x != p.x || y != p.y; }
	bool operator<(const Point &p) { return x < p.x || (x == p.x && y < p.y); }

	friend Point turn90(const Vec &v) { return {-v.y, v.x}; }
	friend T dot(const Vec &u, const Vec &v) { return u.x*v.x + u.y*v.y; }
	friend T det(const Vec &u, const Vec &v) { return u.x * v.y - u.y * v.x; }
	friend T norm2(const Vec &u) { return dot(u, u); } 

	friend bool turnLeft(const Point &a, const Point &b, const Point &c) {
		return det(b-a, c-a) > 0;
	}
	// -1: turn right / 0: aligned / 1: turn left
	friend int orientation(const Point &a, const Point &b, const Point &c) {
		T d = det(b-a, c-a);
		return d == 0 ? 0 : (d > 0 ? 1 : -1);
	}

	friend bool intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
		const Vec u = b-a;
		const Vec v = d-c;
		const Vec u_orth = turn90(u);
		const Vec v_orth = turn90(v);

		const T ac_v_orth = dot(c-a, v_orth);
		const T u_v_orth = dot(u, v_orth);
		if(u_v_orth == 0) {
			if(ac_v_orth != 0) return false; 
		} else if(u_v_orth > 0) {
			if(ac_v_orth < 0 || ac_v_orth > u_v_orth) return false;
		} else {
			if(ac_v_orth > 0 || ac_v_orth < u_v_orth) return false;
		}

		const T ca_u_orth = dot(a-c, u_orth);
		const T v_u_orth = - u_v_orth;
		if(v_u_orth == 0) {
			if(ca_u_orth != 0) return false; 
		} else if(v_u_orth > 0) {
			if(ca_u_orth < 0 || ca_u_orth > v_u_orth) return false;
		} else {
			if(ca_u_orth > 0 || ca_u_orth < v_u_orth) return false;
		}

		return true;
	}
};
using Pt = Point<ll>;

// Return a clockwise convex hull
template<typename pt>
vector<pt> convex_hull(vector<pt>& pts, bool include_collinear=false) {
	if(pts.size() < 3) return pts;
	pt p0 = *min_element(pts.begin(), pts.end(), [](const pt &a, const pt &b) {
		return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	});
	sort(pts.begin(), pts.end(), [&p0](const pt& a, const pt& b) {
		int o = orientation(p0, a, b);
		if(o == 0) return norm2(a-p0) < norm2(b-p0);
		return o < 0;
	});
	if(include_collinear) {
		auto it = pts.end()-1;
		while(it >= pts.begin() && orientation(p0, *it, pts.back()) == 0) --it;
		reverse(++it, pts.end());
	}
	vector<pt> st;
	for(const pt &a : pts) {
		while(st.size() > 1 && orientation(st[st.size()-2], st.back(), a) >= (include_collinear ? 1 : 0))
			st.pop_back();
		st.push_back(a);
	}
	return st;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n;
	vector<Pt> ps(n);
	for(auto &x : ps) cin >> x;
	cin >> q;
	vector<Pt> qs(q);
	for(auto &x : qs) cin >> x;

	vector<int> order(q);
	vector<double> ans(q);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return qs[i].x * qs[j].y > qs[j].x * qs[i].y;
	});

	auto ch = convex_hull(ps);
	reverse(ch.begin(), ch.end());
	int i = 0;
	for(int j = 0; j < (int) ch.size(); ++j) if(ch[j].y > ch[i].y) i = j;

	bool ok = true;
	for(int l : order) {
		auto [c, d] = qs[l];
		int i0 = i;
		while(ok) {
			if(d * ch[i].x <= c * ch[i].y) {
				ans[l] = (double) d / double(ch[i].y);
				break;
			}
			int j = (i+1) % ch.size();
			if(d * ch[j].x <= c * ch[j].y) {
				double u = d * ch[i].x - c * ch[i].y; // > 0
				double v = d * ch[j].x - c * ch[j].y; // <= 0
				double t = (-v) / (u-v);
				double y = ch[j].y + t * (ch[i].y - ch[j].y);
				ans[l] = (double) d / y;
				break;
			}
			i = j;
			if(i == i0) ok = false;
		}
		if(!ok) ans[l] = -1;
	}

	cout << fixed << setprecision(10);
	for(double x : ans) {
		if(x < 0.) cout << "-1\n";
		else cout << x << '\n';
	}

	return 0;
}