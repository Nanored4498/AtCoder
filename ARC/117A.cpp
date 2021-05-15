#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;
	if(A >= B) {
		for(int i = 1; i <= A; ++i) std::cout << i << ' ';
		for(int i = 1; i < B; ++i) std::cout << -i << ' ';
		cout << (B*(B-1) - A*(A+1))/2 << '\n';
	} else {
		for(int i = 1; i < A; ++i) std::cout << i << ' ';
		for(int i = 1; i <= B; ++i) std::cout << -i << ' ';
		cout << (B*(B+1) - A*(A-1))/2 << '\n';
	}

	return 0;
}