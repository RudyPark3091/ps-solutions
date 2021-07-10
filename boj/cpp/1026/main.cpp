/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n;
int a1[51];
int a2[51];

void setup() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a2[i];
	}
}

void solve() {
	sort(a1, a1 + n);
	sort(a2, a2 + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a1[i] * a2[n - i - 1];
	}
	cout << sum << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
