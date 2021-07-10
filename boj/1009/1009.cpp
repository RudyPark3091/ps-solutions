#include <iostream>
using namespace std;

int t;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b, res = 1;
    cin >> a >> b;
    for (int j = 0; j < b % 4 + 4; j++) {
      res *= a;
      res %= 10;
    }

    if (res == 0) { cout << 10 << '\n'; }
    else { cout << res << '\n'; }
  }

  return 0;
}
