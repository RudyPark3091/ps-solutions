/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int ans = 0;
	string x;
	cin >> x;

	for (int i = 0; i < x.length(); i++) {
		int c = (int) x[i] - '0';
		int p = (int) pow(16, x.length() - i - 1);

		if (c < 10) {
			ans += p * c;
		} else {
			ans += p * ((int) x[i] - 'A' + 10);
		}
	}
	cout << ans << '\n';

	return 0;
}
