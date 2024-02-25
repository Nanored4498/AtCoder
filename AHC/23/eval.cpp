#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;
using vi = vector<int>;

const int NT = 50;
const int MAXD = 4;
const int MAX_EXP = 50;

struct Crop { int S, D; };
struct Plan { int k, i, j, s; };

int main(int argc, char* argv[]) {
	if(argc <= 1) {
		cerr << "Generator takes one argument: the solution programm" << endl;
		return 1;
	}

	double score = 0.;
	double n_inputs = 0.;
	char gencmd[] = "./gen 9 > in.txt";
	char solcmd[256];
	sprintf(solcmd, "%s < in.txt > out.txt", argv[1]);
	for(int it_exp = 0; it_exp < MAX_EXP; ++it_exp) {
		for(int d = 1; d <= MAXD; ++d) {
			gencmd[6] = '0'+d;
			if(system(gencmd)) {
				cerr << "Generator failed" << endl;
				return 1;
			}
			if(system(solcmd)) {
				cerr << "Solution failed" << endl;
				return 1;
			}

			// input
			int T, H, W, K, i0;
			vector<Crop> crops;
			vector<vi> G;
			{
				ifstream in("in.txt");
				in >> T >> H >> W >> i0;
				vector<string> hwalls(H-1), vwalls(H);
				for(string &ws : hwalls) in >> ws;
				for(string &ws : vwalls) in >> ws;
				in >> K;
				crops.resize(K);
				for(Crop &c : crops) in >> c.S >> c.D;
				G.resize(H*W);
				for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) {
					const int k = i + j*H;
					if(i+1 < H && hwalls[i][j] == '0') {
						G[k].push_back(k+1); 
						G[k+1].push_back(k);
					}
					if(j+1 < W && vwalls[i][j] == '0') {
						G[k].push_back(k+H); 
						G[k+H].push_back(k);
					}
				}
			}

			// output
			vector<Plan> sol;
			double X = 0.;
			{
				ifstream in("out.txt");
				int M;
				in >> M;
				if(M < 0 || M > crops.size()) {
					cerr << "Wrong answer! Bad value for M" << endl;
					return 1;
				}
				sol.resize(M);
				vector<bool> used(crops.size(), false);
				for(auto &[k, i, j, s] : sol) {
					in >> k >> i >> j >> s;
					--k;
					if(i < 0 || i >= H || j < 0 || j >= W) {
						cerr << "Wrong answer! Bad location" << endl;
						return 1;
					}
					if(k < 0 || k >= crops.size() || used[k]) {
						cerr << "Wrong answer! Bad crop index " << k << '/' << crops.size() << endl;
						return 1;
					}
					if(s > crops[k].S || s < 1) {
						cerr << "Wrong answer! Bad planting time" << endl;
						return 1;
					}
					used[k] = true;
					X += crops[k].D - crops[k].S + 1;
				}
			}
			
			score += X / (H*W*T) * 1e6;
		}
		n_inputs += 4.;
		cout << '\r' << (NT * score / n_inputs) << "      " << flush;
	}
	cout << endl;

	return 0;
}