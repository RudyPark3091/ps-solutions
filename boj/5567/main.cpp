/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n, m;
bool arr[501][501];
bool yes[501];

void setup() {
  int a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    arr[a][b] = true;
    arr[b][a] = true;
  }
}

void solve() {
  for (int i = 2; i <= n; i++) {
    if (arr[1][i]) {
      yes[i] = true;
      for (int j = 2; j <= n; j++) {
        if (arr[i][j]) yes[j] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 2; i <= n; i++) if (yes[i]) ans++;
  cout << ans << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
