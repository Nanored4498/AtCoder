#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int C = 52;
const int S = C*C*C;

int convert(const string &s) {
	int ans = 0;
	for(const char &c : s)
		ans = ans * C + ((c >= 'a' && c <= 'z') ? c-'a' : 26+c-'A');
	return ans;
}

vi to[S], from[S];
// 0:lose, 1:win, 2:draw
vi state(S, 2), out(S, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vi ends(N);
	for(int i = 0; i < N; ++i) {
		string w;
		cin >> w;
		int s = convert(w.substr(0, 3));
		int e = convert(w.substr(w.size()-3, 3));
		ends[i] = e;
		to[s].push_back(e);
		from[e].push_back(s);
        ++ out[s];
	}

    vi Q;
    for(int x = 0; x < S; ++x) if(out[x] == 0) Q.push_back(x);
    while(!Q.empty()) {
        int x = Q.back();
        Q.pop_back();
        state[x] = 0;
        for(int y : from[x]) if(state[y] != 1) {
            state[y] = 1;
            for(int z : from[y]) if(--out[z] == 0) Q.push_back(z);
        }
    }

	for(int x : ends) {
		if(state[x] == 0) cout << "Takahashi\n";
		else if(state[x] == 1) cout << "Aoki\n";
		else cout << "Draw\n";
	}

	return 0;
}