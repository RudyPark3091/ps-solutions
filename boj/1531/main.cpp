/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n, m;
int arr[100][100] = { { 0 } };

void setup() {
  int x1, y1, x2, y2;
  cin >> n >> m;
  for (int k = 0; k < n; k++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1 - 1; i < x2; i++) {
      for (int j = y1 - 1; j < y2; j++) {
        arr[i][j] += 1;
      }
    }
  }
}

void solve() {
  int ans = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (arr[i][j] > m) ans += 1;
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
