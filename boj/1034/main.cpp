/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;
typedef long long ll;

int n, m, k;
string arr[51];

void setup() {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int ans = 0;
	setup();
	for (int i = 0; i < n; i++) {
		int off = 0;
		int sum = 0;

		for (int j = 0; j < m; j++) {
			off += arr[i][j] == '0' ? 1 : 0;
		}

		if (off <= k && off % 2 == k % 2) {
			for (int j = 0; j < n; j++) {
				sum += arr[i] == arr[j] ? 1 : 0;
			}
		}

		ans = max(sum, ans);
	}
	cout << ans << '\n';
	return 0;
}
