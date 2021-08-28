/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n, k;
string arr[101];

void setup() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> k;
}

void solve() {
  switch (k) {
    case 1:
      for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
      break;
    case 2:
      for (int i = 0; i < n; i++) {
        for (int j = arr[i].length() - 1; j >= 0; j--)
          cout << arr[i][j];
        cout << '\n';
      }
      break;
    case 3:
      for (int i = 0; i < n; i++)
        cout << arr[n - i - 1] << '\n';
      break;
  }
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
