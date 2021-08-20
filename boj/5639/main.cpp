/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int arr[10001];
int n = 0;

void setup() {
  int x;
  while (cin >> x) {
    arr[n++] = x;
  }
}

void solve(int left, int right) {
  if (left >= right) return;

  int idx = left + 1;
  for (int i = idx; i < right; i++) {
    if (arr[i] > arr[left]) {
      idx = i;
      break;
    }
  }

  solve(left + 1, idx);
  solve(idx, right);

  cout << arr[left] << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve(0, n);

	return 0;
}
