#include <iostream>
#define MOD 1000000000
using namespace std;

int main() {
	int n;
	int f = 1;
	cin >> n;

	if (n < 0) {
		n *= -1;
		if (n % 2 == 0) f = -1;
	}
	if (n == 0) f = 0;

	long long a = 0, b = 1, c = 1;

	for (int i = 2; i < n; i++) {
		a = b;
		b = c;
		c = (a % MOD + b % MOD) % MOD;
	}

	cout << f << '\n';
	if (n == 0) cout << 0 << '\n';
	else cout << c << '\n';

	return 0;
}
