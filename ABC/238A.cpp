#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n >= 30 || (1<<n) > n*n) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}