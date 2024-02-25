#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template<typename T>
struct Fenwick {
	#define LSB(i) ((i)&(-(i)))
	vector<T> v;

	Fenwick() = default;
	Fenwick(int n): v(n+1, 0) {}

	void init() {
		for(int i = 1; i < (int) v.size(); ++i) v[i] += v[i-1];
		for(int i = v.size()-1; i > 0; --i) v[i] -= v[i-LSB(i)];
	}

	void add(int i, T x) {
		for(; i < (int) v.size(); i += LSB(i)) v[i] += x;
	}
	void set(int i, T x) { add(i, x - querry(i, i)); }

	T querry(int i) {
		T ans = 0;
		for(; i > 0; i -= LSB(i)) ans += v[i];
		return ans;
	}
	T querry(int a, int b) { return querry(b) - querry(a-1); }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, d;
	cin >> n >> l >> d;
	++n;
	++l;

	Fenwick<double> y(n);
	y.add(1, 1.);
	for(int i = 2; i <= n; ++i) {
		int a = max(1, i-d);
		int b = min(l-1, i-1);
		if(a > b) break;
		double s = y.querry(a, b);
		y.add(i, s/d);
	}

	vector<double> py(n+1), sy(n+1, 0), sy2(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		py[i] = i >= l ? y.querry(i, i) : 0.;
		sy[i] = sy[i-1] + py[i];
		sy2[i] = sy2[i-1] + sy[i];
	}

	double YL = 1.-sy.back();
	double pw = YL;
	double ans = pw;
	double p = 1.;
	vector<double> add(n+1, 0.);
	add[2] = -1.;
	for(int i = 1; i <= n; ++i) {
		p += add[i];
		if(i) pw -= p * sy[i-1];
		double p2 = p/d;
		if(i+1 <= n) add[i+1] += p2;
		if(i+d+1 <= n) add[i+d+1] -= p2;
		int k = min(i+d-1, n-1);
		pw += p2 * (sy2[k] - sy2[i-1]);
		pw -= p2 * YL * max(0, i+d-n);
		ans = max(ans, pw);
	}
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}