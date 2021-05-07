/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n, k;
int arr[1001];
int cnt = 0;

void solve() {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; i * j <= n; j++) {
			if (arr[i * j] != -1) {
				cnt++;
				if (cnt == k) {
					cout << arr[i * j] << '\n';
					return;
				}

				arr[i * j] = -1;
			}
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) arr[i] = i;
	solve();

	return 0;
}
