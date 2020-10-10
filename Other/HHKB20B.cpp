#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int W, H;
	cin >> H >> W;
	string S[102];
	for(int i = 0; i < H; ++i) cin >> S[i];
	int ans = 0;
	for(int i = 0; i < H; ++i)
		for(int j = 0; j < W; ++j) if(S[i][j] == '.') {
			if(i > 0 && S[i-1][j] == '.') ++ ans;
			if(j > 0 && S[i][j-1] == '.') ++ ans;
		}
	cout << ans << endl;

	return 0;
}