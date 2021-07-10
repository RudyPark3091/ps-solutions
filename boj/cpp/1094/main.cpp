/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int main() {
	int x, cnt = 0;
	cin >> x;

	while (x >= 1) {
		if (x % 2) {
			cnt++;
		}
		x /= 2;
	}

	cout << cnt << '\n';
	return 0;
}
