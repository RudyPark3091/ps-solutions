#include <iostream>
using namespace std;

long long n, m;

int foo(long long num, long long d) {
    int fnum = 0;
    for (long long i = d; num/i >= 1; i *= d) { fnum += num/i; }
    return fnum;
}

int main() {
    int t = 0;
    int f = 0;
    cin >> n >> m;

    t = foo(n, 2) - foo(n-m, 2) - foo(m, 2);
    f = foo(n, 5) - foo(n-m, 5) - foo(m, 5);

    if (t <= f) { cout << t << '\n'; }
    if (t > f) { cout << f << '\n'; }

    return 0;
}