#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vi A(N), B(N);
	for(int i = 0; i < N; ++i) cin >> A[i] >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if(N % 2 == 0) cout << 1 + B[N/2] + B[N/2-1] - A[N/2] - A[N/2-1] << "\n";
	else cout << 1 + B[N/2] - A[N/2] << "\n";

	return 0;
}