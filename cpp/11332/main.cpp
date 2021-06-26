/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <cmath>
#define TLE "TLE!"
#define PASS "May Pass."
#define OP 100'000'000
using namespace std;

long long fac[15] = { 1, };

void init() {
	for (int i = 1; i < 15; i++) {
		fac[i] = fac[i - 1] * (i + 1);
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long c, n, t, l;
	string s;
	cin >> c;

	init();
	for (int i = 0; i < c; i++) {
		bool pass = true;
		cin >> s >> n >> t >> l;
		l *= OP;
		l /= t;

		if (s =="O(N)" && n > l) pass = false;
		else if (s == "O(N^2)" && n * n > l) pass = false;
		else if (s == "O(N^3)" && n * n * n > l) pass = false;
		else if (s == "O(2^N)" && n > (long long) log2(l)) pass = false;
		else if (s == "O(N!)") {
			if (n >= 13) pass = false;
			else if (fac[n - 1] > l) pass = false;
		}
		cout << (pass ? PASS : TLE) << '\n';
	}

	return 0;
}
