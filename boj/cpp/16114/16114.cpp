#include <iostream>
using namespace std;

int calc(int _x, int _n) {
	int r = 0;
	int X = _x;
	while (X > 0) {
		r += 1;
		X -= _n / 2;
	}
	return r - 1;
}

int main() {
	int x, n;
	cin >> x >> n;

	if (n == 1) {
		if (x >= 0) cout << 0 << '\n';
		else cout << "INFINITE" << '\n';
	}
	else if (n == 0) {
		if (x > 0) cout << "INFINITE" << '\n';
		else cout << 0 << '\n';
	}
	else if (n % 2 == 1) cout << "ERROR" << '\n';
	else {
		if (x > 0) cout << calc(x, n) << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}
