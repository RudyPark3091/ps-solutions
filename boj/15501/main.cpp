/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> srs;
vector<int> test;

void setup() {
  cin >> n;
  srs.reserve(n);
  test.reserve(n);
  for (int i = 0; i < n; i++) cin >> srs[i];
  for (int i = 0; i < n; i++) cin >> test[i];
}

int find(int x) {
  for (int i = 0; i < n; i++) {
    if (test[i] == x) return i;
  }
}

void solve() {
  int idx = find(srs[0]);
  int base = idx;
  int right = idx < n
    ? (test[idx + 1] == srs[1])
    : (test[0] == srs[1]);

  for (int i = 0; i < n - 1; i++) {
    if (right) {
      bool no = test[(idx + 1) % n] != srs[i + 1];
      idx = (idx + 1) % n;
      if (no) {
        cout << "bad puzzle" << '\n';
        return;
      }
    } else {
      bool no = test[(idx - 1 + n) % n] != srs[i + 1];
      idx = (idx - 1 + n) % n;
      if (no) {
        cout << "bad puzzle" << '\n';
        return;
      }
    }
  }
  cout << "good puzzle" << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
