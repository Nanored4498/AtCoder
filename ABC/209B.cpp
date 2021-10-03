#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    int s = 0;
    for(int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        s += a;
        if(i&1) --s;
    }
    cout << (X >= s ? "Yes" : "No") << endl; 

    return 0;
}