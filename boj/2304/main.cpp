#include <iostream>
using namespace std;

int n, x, y, _max, ans = 0;
int arr[3][1001];

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    arr[0][x] = y;
  }

  for (int i = 0; i < 1001; i++) {
    _max = max(arr[0][i], _max);
    arr[1][i] = _max;
  }
  _max = 0;
  for (int i = 1000; i >= 0; i--) {
    _max = max(arr[0][i], _max);
    arr[2][i] = _max;
  }
  for (int i = 0; i < 1001; i++) {
    ans += min(arr[1][i], arr[2][i]);
  }
  cout << ans << '\n';
  return 0;
}
