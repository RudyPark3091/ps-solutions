#include <iostream>
using namespace std;

long long a, b, c;

long long solve(int x, int y, int d) {
  if (y == 0) { return 1; }
  else if (y == 1) { return x % d; }
  else if (y > 1) {
    long long num = solve(x, y/2, d);
    num = num * num % d;
    if (y % 2 == 0) { return num; }
    else { return x * num % d; }
  }
}

int main() {
  cin >> a >> b >> c;
  cout << solve(a, b, c) << '\n';
  return 0;
}
