#include <iostream>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

const pii adj[4] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(int argc, char* argv[]) {
	if(argc <= 1) {
		cerr << "Generator takes one argument: the parameter d" << endl;
		return 1;
	}
	const int d = atoi(argv[1]);
	if(d < 1 || d > 4) {
		cerr << "The parameter d should be between 1 and 4" << endl;
		return 1;
	}

	const auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937_64 mt(seed);

	const int T = 100;
	const int H = 20;
	const int W = 20;

	uniform_int_distribution<int> i0_dist(0, H-1);
	const int i0 = i0_dist(mt);

	cout << T << ' ' << H << ' ' << W << ' ' << i0 << '\n';

	vector<string> hwalls(H-1, string(W, '0'));
	vector<string> vwalls(H, string(W-1, '0'));
	vector<vector<bool>> marked(H+1, vector<bool>(W+1, false));
	vector<vi> seen(H+1, vi(W+1, 0));
	vector<pii> mark;
	for(int i = 0; i <= H; ++i) {
		mark.emplace_back(i, 0);
		mark.emplace_back(i, W);
		marked[i][0] = marked[i][W] = true;
	}
	for(int i = 1; i < W; ++i) {
		mark.emplace_back(0, i);
		mark.emplace_back(H, i);
		marked[0][i] = marked[H][i] = true;
	}
	for(int S = 1; true; ++S) {
		for(const auto &[i, j] : mark) seen[i][j] = S;
		vector<pii> Q = mark, Q2;
		int ns = 0;
		for(int e = 0; e < d; ++e) {
			ns += Q.size();
			for(const auto &[i, j] : Q) for(const auto &[x, y] : adj) {
				const int u = i+x;
				if(u < 0 || u > H) continue;
				const int v = j+y;
				if(v < 0 || v > W) continue;
				if(seen[u][v] == S) continue;
				seen[u][v] = S;
				Q2.emplace_back(u, v);
			}
			swap(Q, Q2);
			Q2.clear();
		}
		ns += Q.size();
		const int nns = (H+1)*(W+1) - ns;
		if(!nns) break;
		int v = uniform_int_distribution<int>(1, nns)(mt);
		int h, w;
		for(int i = 1; v; ++i) for(int j = 1; j < W; ++j) if(seen[i][j] != S) if(!(--v)) {
			h = i;
			w = j;
			break;
		}
		++ S;
		vector<pii> org;
		Q.assign(1, {h, w});
		while(org.empty()) {
			for(const auto &[i, j] : Q) for(const auto &[x, y] : adj) {
				const int u = i+x;
				if(u < 0 || u > H) continue;
				const int v = j+y;
				if(v < 0 || v > W) continue;
				if(seen[u][v] == S) continue;
				if(marked[u][v]) org.emplace_back(u, v);
				seen[u][v] = S;
				Q2.emplace_back(u, v);
			}
			swap(Q, Q2);
			Q2.clear();
		}
		const auto [h2, w2] = org[uniform_int_distribution<int>(0, org.size()-1)(mt)];
		if(uniform_int_distribution<char>(0, 1)(mt)) {
			while(h != h2) {
				if(!marked[h][w]) {
					mark.emplace_back(h, w);
					marked[h][w] = true;
				}
				if(h < h2) {
					vwalls[h][w-1] = '1';
					++ h;
				} else {
					vwalls[h-1][w-1] = '1';
					-- h;
				}
			}
			while(w != w2) {
				if(!marked[h][w]) {
					mark.emplace_back(h, w);
					marked[h][w] = true;
				}
				if(w < w2) {
					hwalls[h-1][w] = '1';
					++ w;
				} else {
					hwalls[h-1][w-1] = '1';
					-- w;
				}
			}
		} else {
			while(w != w2) {
				if(!marked[h][w]) {
					mark.emplace_back(h, w);
					marked[h][w] = true;
				}
				if(w < w2) {
					hwalls[h-1][w] = '1';
					++ w;
				} else {
					hwalls[h-1][w-1] = '1';
					-- w;
				}
			}
			while(h != h2) {
				if(!marked[h][w]) {
					mark.emplace_back(h, w);
					marked[h][w] = true;
				}
				if(h < h2) {
					vwalls[h][w-1] = '1';
					++ h;
				} else {
					vwalls[h-1][w-1] = '1';
					-- h;
				}
			}
		}
	}
	for(string &s : hwalls) cout << s << '\n';
	for(string &s : vwalls) cout << s << '\n';

	uniform_real_distribution<double> L_dist(1., 2.);
	const int L = round(H*W*T * L_dist(mt));
	int sumL = 0;
	vector<pii> SD;
	while(sumL < L) {
		int Lk = 0;
		while(Lk < 2 || Lk > T) Lk = round(pow(10., normal_distribution<double>(1.0, 0.25)(mt)));
		sumL += Lk;
		const int D = uniform_int_distribution<int>(Lk, T)(mt);
		const int S = D - Lk + 1;
		SD.emplace_back(S, D);
	}
	cout << SD.size() << '\n';
	for(const auto &[S, D] : SD) cout << S << ' ' << D << '\n';


	return 0;
}