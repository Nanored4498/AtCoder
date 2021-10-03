#include <iostream>
#include <algorithm>
#include <vector>

#include "../CPHeaders/mod_arith.h"

using namespace std;
typedef vector<int> vi;
const int MOD = 1e9+7;
typedef mint<MOD> mi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vi A(N);
    for(int &x : A) cin >> x;
    sort(A.begin(), A.end());

    mi ans = 1;
    for(int i = 0; i < N; ++i)
        ans *= max(0, A[i]-i);
    cout << ans << endl;

    return 0;
}