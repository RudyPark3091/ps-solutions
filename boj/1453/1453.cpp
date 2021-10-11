#include <iostream>
using namespace std;

int n, x;
bool arr[101];

int main() {
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (arr[x]) ans++;
    else arr[x] = true;
  }

  cout << ans << '\n';
  return 0;
}
