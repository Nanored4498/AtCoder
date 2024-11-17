#include <iostream>
#include <vector>

using namespace std;

struct UF {
	vector<int> r;
	UF(int n): r(n, -1) {}
	int find(int i) {
		if(r[i] < 0) return i;
		return r[i] = find(r[i]);
	}
	void merge(int i, int j) {
		i = find(i); j = find(j);
		if(i == j) return;
		if(r[i] > r[j]) swap(i, j);
		r[i] += r[j];
		r[j] = i;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	UF uf(N+1);
	vector<int> l(N+1), r(N+1), col(N+1), C(N+1, 1);
	for(int i = 1; i <= N; ++i) l[i] = r[i] = col[i] = i;
	while(Q--) {
		int t, x, c;
		cin >> t;
		if(t == 1) {
			cin >> x >> c;
			x = uf.find(x);
			C[col[x]] += uf.r[x];
			col[x] = c;
			C[col[x]] -= uf.r[x];
			if(l[x] > 1) {
				const int y = uf.find(l[x]-1);
				if(col[y] == c) {
					uf.merge(x, y);
					const int z = uf.find(x);
					l[z] = l[y];
					r[z] = r[x];
					x = z;
				}
			}
			if(r[x] < N) {
				const int y = uf.find(r[x]+1);
				if(col[y] == c) {
					uf.merge(x, y);
					const int z = uf.find(x);
					l[z] = l[x];
					r[z] = r[y];
					x = z;
				}
			}
		} else /* t == 2 */ {
			cin >> c;
			cout << C[c] << '\n';
		}
	}

	return 0;
}