/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[5000001];

void solve() {
	sort(arr, arr + n);
	cout << arr[k - 1] << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve();

	return 0;
}
