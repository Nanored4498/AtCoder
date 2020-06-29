#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int X;
	cin >> X;
	int g = __gcd(360, X);
	int K = 360 / g;
	cout << K << "\n";

	return 0;
}