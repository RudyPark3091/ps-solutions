/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

void solve(int n) {
	int ans = 0;
	int p = 1;
	int i;
	for (i = 1; i <= 8; i++) {
		if (p * 10 > n) break;
		ans += i * (9 * p);
		p *= 10;
	}
	cout << i << '\n';
	ans += i * (n - p + 1);
	cout << ans << '\n';
}

int main() {
	int n;
	cin >> n;
	if (n < 10) cout << n << '\n';
	else solve(n);

	return 0;
}
