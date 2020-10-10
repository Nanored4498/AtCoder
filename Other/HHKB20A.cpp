#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char S, T;
	cin >> S >> T;
	if(S == 'Y') T += 'A'-'a';
	cout << T << endl;

	return 0;
}