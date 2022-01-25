/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#define MAX 100'001
using namespace std;

int n;
int arr[MAX];

void solve() {
  for (int i = 1; i <= n; i++) arr[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
      arr[i] = min(arr[i], arr[i - j * j] + 1);
    }
  }
  cout << arr[n] << '\n';
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n;
  solve();

  return 0;
}
