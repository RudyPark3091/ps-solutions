#include <iostream>
using namespace std;

int fac(int n) {
    return n >= 1 ? n * fac(n-1) : 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    int res = fac(n) / (fac(k) * fac(n-k));

    cout << res << '\n';
    return 0;
}