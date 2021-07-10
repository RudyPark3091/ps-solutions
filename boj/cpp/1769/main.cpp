/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

void solve(string x, int depth) {
	if (x.length() < 2) {
		cout << depth << '\n';
		if (x == "3" || x == "6" || x == "9")
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		return;
	}

	int sum = 0;
	for (int i = 0; i < x.length(); i++)
		sum += (int) x[i] - '0';
	solve(to_string(sum), depth + 1);
}

int main() {
	string x;
	cin >> x;
	solve(x, 0);
	return 0;
}
