#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string T;
	cin >> T;
	for(int i = 0; i < T.size(); ++i) if(T[i] == '?') T[i] = 'D';
	cout << T << "\n";

	return 0;
}