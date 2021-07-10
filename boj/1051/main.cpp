/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
// int arr[51][51] = { -1 } => (X)
// fill(&arr[0][0], &arr[50][50], -1) => (O)
int arr[51][51];

void setup() {
	fill(&arr[0][0], &arr[50][51], -1);
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = (int) s[j] - '0';
		}
	}
}

bool coords(int x, int y, int l) {
	if (arr[x][y] == arr[x + l][y] &&
			arr[x][y] == arr[x][y + l] &&
			arr[x][y] == arr[x + l][y + l]) return true;
	return false;
}

void solve() {
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k < min(n - i + 1, m - j + 1); k++) {
				if (coords(i, j, k)) ans = max(ans, (k + 1) * (k + 1));
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
