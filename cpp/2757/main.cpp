/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int c_index(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'C') return i;
	}
}

void solve(int n, int m) {
	char c[7];
	int idx = 0;

	while (m > 0) {
		m -= 1;
		c[idx] = 'A' + m % 26;
		idx += 1;
		m /= 26;
	}

	for (int i = idx - 1; i >= 0; i--) cout << c[i];
	cout << n << '\n';
}

bool parse() {
	string s;
	cin >> s;
	int idx = c_index(s);
	int n = atoi(s.substr(1, idx - 1).c_str());
	int m = atoi(s.substr(idx + 1).c_str());

	if (n == 0 && m == 0) return true;
	else solve(n, m);
	return false;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	while (true) if (parse()) break;
	return 0;
}
