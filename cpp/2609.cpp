#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    int gcd, lcm;

    cin >> n;
    cin >> m;

    gcd = __gcd(n, m);
    cout << gcd << '\n';

    lcm = gcd * (n/gcd) * (m/gcd);
    cout << lcm << '\n';
    return 0;
}