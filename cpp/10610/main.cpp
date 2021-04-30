/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <algorithm>
using namespace std;

string n;
int arr[100001];

int ctoi(char c) {
	return (int) (c - '0');
}

void solve() {
	int sum = 0;
	bool non = true;
	for (int i = 0; i < n.length(); i++) {
		int ni = ctoi(n[i]);
		if (ni == 0) non = false;
		sum += ni;
		arr[i] = ni;
	}

	if (sum % 3 != 0 || non) {
		cout << -1 << '\n';
		return;
	}

	sort(arr, arr + n.length(), greater<int>());
	for (int i = 0; i < n.length(); i++) {
		cout << arr[i];
	}
}

int main() {
	cin >> n;
	solve();

	return 0;
}
