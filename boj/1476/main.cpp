/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int e, s, m;

void solve() {
	int _e, _s, _m;
	int ans = 1;

	while (true) {
		_e = (ans - e) % 15;
		_s = (ans - s) % 28;
		_m = (ans - m) % 19;

		if (_e == 0 && _s == 0 && _m == 0) break;
		else ans++;
	}
	cout << ans << '\n';
}

int main() {
	cin >> e >> s >> m;
	solve();

	return 0;
}
