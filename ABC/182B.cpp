#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		int a, j = 2;
		cin >> a;
		while(a > 1) {
			if(a % j == 0) {
				++ n[j];
				while(a%j == 0) a /= j;
			}
			++ j;
		}
	}
	int ans = 2;
	for(int j = 3; j <= 1000; ++j) if(n[j] > n[ans]) ans = j;
	cout << ans << "\n";

	return 0;
}