#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int N, P;
vector<vi> ds, cs;

void dfs(int i, int j) {
	int d = ds[i][j]+cs[i][j];
	if(i > 0 && d < ds[i-1][j]) {
		ds[i-1][j] = d;
		dfs(i-1, j);
	}
	if(i+1 < N && d < ds[i+1][j]) {
		ds[i+1][j] = d;
		dfs(i+1, j);
	}
	if(j > 0 && d < ds[i][j-1]) {
		ds[i][j-1] = d;
		dfs(i, j-1);
	}
	if(j+1 < N && d < ds[i][j+1]) {
		ds[i][j+1] = d;
		dfs(i, j+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	ds.assign(N, vi(N));
	cs.assign(N, vi(N, 1));
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			ds[i][j] = min(i, min(j, min(N-1-i, N-1-j)));
	int res = 0;
	for(int n = 0; n < N*N; ++n) {
		cin >> P; --P;
		int i = P/N, j = P%N;
		res += ds[i][j];
		cs[i][j] = 0;
		dfs(i, j);
	}
	cout << res << endl;

	return 0;
}