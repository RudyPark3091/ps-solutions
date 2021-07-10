/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500001];

void setup() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
}

void solve() {
	sort(arr, arr + n);
	int query;
	int z;
	for (int i = 0; i < m; i++) {
		cin >> query;
		if (binary_search(arr, arr + n, query)) z = 1;
		else z = 0;
		cout << z << ' ';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
