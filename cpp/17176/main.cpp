/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n;
int ch[53];
string s;

void setup() {
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		ch[x]++;
	}

	cin.ignore();
	getline(cin, s);
}

void solve() {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') ch[0] -= 1;
		else {
			int x = 0;
			if ((int) s[i] > 96) x = (int) s[i] - 'a' + 27;
			else x = (int) s[i] - 'A' + 1;
			ch[x] -= 1;
		}
	}

	for (int i = 0; i < 53; i++) {
		if (ch[i] != 0) {
			cout << 'n' << '\n';
			return;
		}
	}
	cout << 'y' << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
